use std::io::{self, Read, Write};

fn main() -> io::Result<()> {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input)?;

    let mut lines = input.lines();
    let t: i32 = lines.next().unwrap().trim().parse().unwrap();

    for _ in 0..t {
        let line = lines.next().unwrap();
        let mut nums = line.trim().split_whitespace();
        let a: i32 = nums.next().unwrap().parse().unwrap();
        let b: i32 = nums.next().unwrap().parse().unwrap();

        writeln!(io::stdout(), "{}", a + b)?;
    }

    Ok(())
}
