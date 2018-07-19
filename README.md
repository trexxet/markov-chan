# markov-chan
[![CodeFactor](https://www.codefactor.io/repository/github/trexxet/markov-chan/badge)](https://www.codefactor.io/repository/github/trexxet/markov-chan)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3162ed565d32482db56c9088b22444f0)](https://www.codacy.com/app/trexxet/markov-chan?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=trexxet/markov-chan&amp;utm_campaign=Badge_Grade)

Yet another Markov chain text generator

## Build
`cmake CMakeLists.txt && make`

## Usage
* `-l` : generate chain from file
* `-r` : run chain from generated file
* `-v` : enable verbose mode
* `-h` : display help

While running, press Enter to generate a new line

Markov-chan supports wide characters!

Example files ("Evgeniy Onegin" by A.S. Pushkin and 
chain generated from it) are stored in `example-onegin`, 
so you can test Markov-chan by 
`./markov-chan -l example-onegin/source.txt -v` and 
`./markov-chan -r example-onegin/source.txt.mchan`
