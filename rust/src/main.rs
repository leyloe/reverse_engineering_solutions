use std::{
    error::Error,
    io::{self, Write},
};

fn main() -> Result<(), Box<dyn Error>> {
    print!("input: ");

    io::stdout().flush()?;

    let mut buffer = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer)?;

    if buffer.trim_end() != "1jfisadfn4r345jkldf" {
        println!("unsolved");
    } else {
        println!("solved");
    }

    Ok(())
}
