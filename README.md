# Teo ccl library: Teonet c containers library

## 1. Description

The Teo ccl library process basic container at C language.

[Read More](https://github.com/teonet-co/teonet/wikis/tr-udp)

## 2. Installation from sources

### Install project with submodules

    git clone git@gitlab.ksproject.org:teonet/teoccl.git
    cd teoccl
    git submodule update --init


### Install Dependences

There is not dependences


### First time, after got sources from subversion repository

    ./autogen.sh


## 3. Make your application 

    make


## 3.1 Using autoscan to Create configure.ac

After make some global changes in sources code use ```autoscan``` to update projects 
configure.ac


## 4. Installation from repository

### UBUNTU

    http://repo.ksproject.org/ubuntu/
    
### Add repository

    sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 8CC88F3BE7D6113C
    sudo apt-get install -y software-properties-common
    sudo add-apt-repository "deb http://repo.ksproject.org/ubuntu/ teonet main"
    sudo apt-get update

### Install

    sudo apt-get install -y libteoccl

## 5. Run example
    
See example [README.md](examples/README.md)


## 6. Teo ccl documentation

See libteoccl documentation at: http://repo.ksproject.org/docs/libteoccl/
