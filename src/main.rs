extern {
    fn test_start();
    fn test_end();
}

fn main() {
    unsafe {
        test_start();
    }
}

struct A;

impl Drop for A {
    fn drop(&mut self) {
        panic!()
    }
}

#[no_mangle]
pub extern fn test_middle() {
    let _a = A;
    foo();
}

fn foo() {
    let _a = A;
    unsafe {
        test_end();
    }
}
