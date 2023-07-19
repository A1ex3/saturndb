# SaturnDB

SaturnDB is a cross-platform dynamic library that allows you to create and work with a file-based database.

## Features

- Easy to use: SaturnDB provides a simple and intuitive interface for creating, reading, updating, and deleting data in the file-based database.
- Cross-platform compatibility: SaturnDB is designed to work seamlessly on multiple platforms, including macOS, and Linux.
- Efficient data storage: The file-based nature of SaturnDB ensures efficient storage and retrieval of data, making it suitable for small to medium-sized databases.

## Getting Started

To get started with SaturnDB, follow the steps below:

1. Download the latest release of SaturnDB from the [GitHub repository](https://github.com/A1ex3/saturndb).
2. Include the SaturnDB library in your project.
3. Refer to the documentation and code samples provided in the repository to learn how to create and interact with the file-based database.
4. Build and run your application, leveraging the power and simplicity of SaturnDB.

## Methods
```c
typedef enum
{
    EXCEPTION = -1,
    FILE_NOT_EXIST = -2,
    KEY_NOT_FOUND = -3,
    MISSING_PARAMETERS = -4,
    DELETION_ERROR = -5,
}FILE_ERROR;
```
#### Parameters

- `t_hash` (string): file whose name is hashed.
- `key` (string): is key in table.
- `value` (string): is key in table.

### `Put(char t_hash[],char key[],char value[])`

Inserts data into a table

#### Return Value

- `MISSING_PARAMETERS`: if no parameters are specified.
- `0`: in case of successful insertion.

### `Get(char t_hash[],char key[])`

Gets the value by key

#### Return Value

- `value`.
- `NULL`: in case the key is not found or no params.

### `Del(char t_hash[],char key[])`

Deletes data from the table

#### Return Value

- `0`: key has been removed from the table.
- `MISSING_PARAMETERS`: if no parameters are specified.

### `TableDel(char t_hash[])`

Deletes the entire table

#### Return Value

- `MISSING_PARAMETERS`: if no parameters are specified.
- `DELETION_ERROR`: couldn't delete the table.
- `0`: table deleted.

## Contributing

We welcome contributions to SaturnDB! If you encounter any issues, have suggestions, or would like to contribute enhancements, please feel free to submit a pull request or open an issue on the [GitHub repository](https://github.com/A1ex3/saturndb).


## License

SaturnDB is released under the [MIT License](https://github.com/A1ex3/saturndb/blob/master/LICENSE). Feel free to use, modify, and distribute it according to the terms of the license.
