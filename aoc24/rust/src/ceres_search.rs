// scan for X, on finding one, check surrounding space for valid word match
pub fn word_search(input: &str) -> i16 {
    let mut merriness: i16 = 0;

    let lines = input.lines()
        .map(|x| x.chars().collect())
        .collect::<Vec<Vec<char>>>();
    let n_lines = lines.len();
    let n_chars = lines[0].len();

    for i in 0..n_lines {
        for j in 0..n_chars {
            if lines[i][j] != 'X' { continue; }

            // right
            if j < n_chars-3 && lines[i][j+1] == 'M' && lines[i][j+2] == 'A' && lines[i][j+3] == 'S' { merriness += 1; }
            // left
            if j > 2 && lines[i][j-1] == 'M' && lines[i][j-2] == 'A' && lines[i][j-3] == 'S' { merriness += 1; }
            // up
            if i > 2 && lines[i-1][j] == 'M' && lines[i-2][j] == 'A' && lines[i-3][j] == 'S' { merriness += 1; }
            // down
            if i < n_lines-3 && lines[i+1][j] == 'M' && lines[i+2][j] == 'A' && lines[i+3][j] == 'S' { merriness += 1; }
            // up-right diag
            if i > 2 && j < n_chars-3 && lines[i-1][j+1] == 'M' && lines[i-2][j+2] == 'A' && lines[i-3][j+3] == 'S' { merriness += 1; }
            // up-left diag
            if i > 2 && j > 2 && lines[i-1][j-1] == 'M' && lines[i-2][j-2] == 'A' && lines[i-3][j-3] == 'S' { merriness += 1; }
            // down-right diag
            if i < n_lines-3 && j < n_chars-3 && lines[i+1][j+1] == 'M' && lines[i+2][j+2] == 'A' && lines[i+3][j+3] == 'S' { merriness += 1; }
            // down-left diag
            if i < n_lines-3 && j > 2 && lines[i+1][j-1] == 'M' && lines[i+2][j-2] == 'A' && lines[i+3][j-3] == 'S' { merriness += 1; }
        }
    }
    
    merriness
}