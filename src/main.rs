use clap::Parser;

mod cli;
mod detect;

fn main() {
    let args = cli::Arguments::parse();
    // println!("{:?}", args);

    let build: bool = args.build || args.run;
    let _run: bool = args.run;

    // For if we use unibuild to build the project
    let cc = detect::used_c_compiler(&args);
    let cxx = detect::used_cpp_compiler(&args);
    println!("\nTrying to build with specified tooling:\n\tC Compiler: {cc}\n\tC++ Compiler: {cxx}");


    if build {
        let a = 
            std::process::Command::new(cc)
            .arg("-v")
            .output();

        if a.is_err() {
            println!("Command not found.");
            return;
        }

        let out = a.unwrap();
        println!("Output:");
        println!("\tstdout:\n{}", String::from_utf8_lossy(&out.stdout));
        println!("\tstderr:\n{}", String::from_utf8_lossy(&out.stderr));    
    }
}