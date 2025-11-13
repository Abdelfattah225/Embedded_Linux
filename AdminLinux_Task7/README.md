# Task 7 – Build Cross Compiler using Crosstool-NG

This task explains how to install, configure, and build a cross-compiler toolchain using Crosstool-NG.
Follow the steps below to clone the project, configure it, select your target architecture, and build the final toolchain.


## 📌 1. Clone Crosstool-NG

```shell
git clone https://github.com/crosstool-ng/crosstool-ng
cd crosstool-ng/
```
![1](./screenshots/1.png)

## 📌 2. List available tags and checkout version crosstool-ng-1.26.rc2 

then You’ll need to run the bootstrap script before running configure:
```shell
git tag
git checkout crosstool-ng-1.26.rc2
```
![2](./screenshots/2.png)
![3](./screenshots/3.png)
![4](./screenshots/4.png)


## 📌 3. Run Bootstrap

Before running ./configure, Crosstool-NG requires running the bootstrap script:
```
./bootstrap
```
![5](./screenshots/5.png)
![6](./screenshots/6.png)

After running bootstrap, the configure file will be generated.

![7](./screenshots/7.png)

## 📌 4. Configure (Hacker’s Way)

Configure Crosstool-NG in local mode:
```
./configure --enable-local
```
![8](./screenshots/8.png)

## 📌 5. Build Crosstool-NG

```
make
```

![9](./screenshots/9.png)

After the build completes, a new executable ct-ng becomes available:

![10](./screenshots/10.png)

## 📌 6. List Available Toolchain Samples

Use Crosstool-NG to list supported architectures:

```
./ct-ng list-samples
```

To use a sample:

```
./ct-ng <sample-name>
```

![11](./screenshots/11.png)
![12](./screenshots/12.png)

## 📌 7. Build the Toolchain

Start the build:
```
./ct-ng build
```

![13](./screenshots/13.png)


## 📌 8. Toolchain Output

After the build finishes successfully, Crosstool-NG creates a folder in $HOME:
Inside it, you will find your full cross-compiler toolchain:

![lib1](./screenshots/lib1.png)
![lib2](./screenshots/lib2.png)





