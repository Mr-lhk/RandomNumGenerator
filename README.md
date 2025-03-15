# RandomNumGenerator

## Introduction

A simple MFC program which can choose one item from a list randomly
Written for personal usage

## Features

- Independent setting file
- Changeable weights
- Automaticlly remove the duplicates
- Simple but beautiful GUI

## Using Method

### Basic

To use this program, you **must** have a setting file according to the format described below

When entering the program, it will automaticlly try to open `settingfile.txt` in the root directory of Drive C 
You can also open a file manually by clicking the "Select File" button

Such operation will automatically followed by a refresh operation, which will cause the reread of the setting file and the erase of the output table, make it possible to select a person again
The refresh can also be comleted by clicking the button

### Setting File Format

The first line contains an integer $length$ , the number of items

Each of the next $length$ lines contains three contents, $id$ , $name$ ,and $weight$ 

The $id$ should be unique

 **Warning:** The file **must** be encoded in ANSI format

## To Do List

- [ ] Add the function of multy-generate 
- [ ] Fix the bugs