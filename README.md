# context-get
This simple utility is designed to lookup the value of a context environment entry for a given name.

## Usage
`context-get CONTEXT_FILE ENVIRONMENT_NAME`

If the context entry exists, the value will be echoed to stdout.
If there are duplicate entries, behavior is undefined.

## Building
### Requirements
* cmake >= 3.13
* make 
* g++ 

### Steps
1. `mkdir build`
1. `cd build`
1. `cmake ..`
1. `make`
