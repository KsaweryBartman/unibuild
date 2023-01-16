use clap::Parser;

#[derive(Parser, Debug, Clone)]
#[clap(about, version)]
/// The unibuild command line utility, by default just builds your project's build scripts as defined in "unibuild.json".
/// You can also build and run your apps directly with unibuild, instead of building a build script, and then using it.
pub struct Arguments {
    #[clap(long, required = false, default_value = "")]
    /// Your chosen C compiler, defaults to clang
    pub cc: String,
    #[clap(long, required = false, default_value = "")]
    /// Your chosen C++ compiler, defaults to clang++
    pub cxx: String,
    #[clap(short, long)]
    /// Builds your project's targets
    pub build: bool,
    #[clap(short, long)]
    /// Builds and runs your project's executable targets
    pub run: bool,
}
