extern crate cc;

fn main() {
    cc::Build::new()
        .file("src/foo.c")
        .compile("foo");
    cc::Build::new()
        .file("src/bar.cpp")
        .cpp(true)
        .compile("bar");
}
