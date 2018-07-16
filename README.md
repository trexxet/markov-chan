# markov-chan
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
