use clap::Parser;

#[derive(Parser, Debug)]
#[clap(about, version)]
/// The unibuild command line utility, by default just builds your project as defined in unibuild.json
struct ClapCli {
    #[clap(long, required = false, default_value = "")]
    /// Your chosen C compiler, defaults to clang
    cc: String,
    #[clap(long, required = false, default_value = "")]
    /// Your chosen C++ compiler, defaults to clang++
    cxx: String,
}

fn main() {
    let found_c_compiler: String;

    let env_cc = std::env::var("CC");
    if env_cc.is_ok() {
        found_c_compiler = env_cc.unwrap();
        println!("Found the C Compiler as an environment variable: {found_c_compiler}");
    }

    let arg_cc = ClapCli::parse();

    println!("{:?}", arg_cc);




    // let a = std::process::Command::new("gcc").arg("-v").output();
    // if a.is_err() {
    //     println!("Command not found.");
    //     return;
    // }
    // let out = a.unwrap();
    // println!("stdout: {}", String::from_utf8_lossy(&out.stdout));
    // println!("stderr: {}", String::from_utf8_lossy(&out.stderr));
}