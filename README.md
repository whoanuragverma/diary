# Diary

A sweet and simple diary application in C

[![Actions Status](https://github.com/whoanuragverma/diary/workflows/build/badge.svg)](https://github.com/whoanuragverma/diary/actions)

## Prerequisite

-   gcc must be installed on your system. Type gcc in your commmand prompt to verify.
-   Additional Prerequisite on windows
    -   You can install GNU make to windows to simplify the compilation process via [Chocolatey](https://chocolatey.org/install).
    -   If you have Chocolatey already installed, then install GNU make by running with admin permission(obv.)

```bash
choco install make
```

## Usage

Clone this repository and navigate to project's directory and type in cmd

```bash
# If you have GNU make installed on Windows or you're on Linux
make

# If you only have gcc installed then run this
gcc main.c encryption/encryption.c -lm -o main
./main
# PS: This command can get more longer as we add more file.
# It is recommended to install GNU make on your system.
```

## Contributing

Pull requests are welcome just make sure that **they are not on main/master branch** otherwise they may be rejected. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
