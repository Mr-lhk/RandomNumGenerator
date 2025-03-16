# RandomNumGenerator

## Introduction

A simple MFC program which can choose one item from a list randomly  
Written for personal usage

## Features

- Independent setting file
- Changeable weights
- Automaticlly remove the duplicates
- Simple but beautiful GUI
- Independent program, no need for the Internet

## Using Method

### Basic

To use this program, you **must** have a setting file according to the format described below

When entering the program, it will automaticlly try to open `settingfile.txt` in the root directory of Drive C  
You can also open a file manually by clicking the "Select File" button

Such operation will automatically followed by a refresh operation, which will cause the reread of the setting file and the erase of the output table, make it possible to select a person again  
The refresh can also be comleted by clicking the button

The program provides two ways to generate new random nums, single-generation and multi-generation  
Click the button of single-generation, and a new num will be generated, if possible
You can also click the arrows to change the frequency of the multi-generation function, which is shown in the text box beside. Then click the button of multi-generate to generate random nums according to the frequency

### Setting File Format

 **Warning:** The file **must** be encoded in ANSI format!

The first line contains an integer $length$ , the number of items

Each of the next $length$ lines contains three contents, $id$ , $name$ ,and $weight$ 

The $id$ should be unique

An example of the settingfile as below

```testingfile.txt
5
1 name1 10
2 name2 20
3 name3 30
4 name4 100
5 name5 100
```

## To Do List

- [x] Add the function of multi-generate 
- [ ] Fix the bugs
- [ ] Optimize the weight function
