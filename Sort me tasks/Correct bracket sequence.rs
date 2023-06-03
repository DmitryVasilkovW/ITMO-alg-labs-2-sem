use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let sequence = input.trim();

    let mut stack = Vec::new();
    for c in sequence.chars() {
        match c {
            '(' => stack.push(c),
            ')' => {
                if stack.pop() != Some('(') {
                    println!("NO");
                    return;
                }
            }
            _ => panic!("Unexpected character"),
        }
    }

    if stack.is_empty() {
        println!("YES");
    } else {
        println!("NO");
    }
}
