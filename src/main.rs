use clap::Parser;

mod cli;
mod detect;

fn main() {
    let args = cli::Arguments::parse();
    // println!("{:?}", args);

    let build: bool = args.build || args.run;
    let _run: bool = args.run;

    if build {
        // For if we use unibuild to build the project
        let cc = detect::used_c_compiler(&args);
        let cxx = detect::used_cpp_compiler(&args);
        println!("\nTrying to build with specified tooling:\n\tC Compiler: {cc}\n\tC++ Compiler: {cxx}");
    
        let check = 
            std::process::Command::new(cc.as_str())
            .arg("-v")
            .output();

        if check.is_err() {
            println!("C compiler \"{cc}\" not found!");
            return;
        }

        let check = 
            std::process::Command::new(cxx.as_str())
            .arg("-v")
            .output();

        if check.is_err() {
            println!("C++ compiler \"{cxx}\" not found!");
            return;
        }
    }
}