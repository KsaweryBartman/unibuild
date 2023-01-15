use crate::cli;

pub fn used_c_compiler(args: &cli::Arguments) -> String {
  let from_args = args.cc.clone();
  if !from_args.is_empty() {
      return from_args;
  }

  let from_env = std::env::var("CC");
  if from_env.is_ok() {
      return from_env.unwrap();
  }

  return String::from("clang");
}

pub fn used_cpp_compiler(args: &cli::Arguments) -> String {
  let from_args = args.cxx.clone();
  if !from_args.is_empty() {
      return from_args;
  }

  let from_env = std::env::var("CXX");
  if from_env.is_ok() {
      return from_env.unwrap();
  }

  return String::from("clang++");
}