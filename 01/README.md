build
```
gcc main.c -o main -lSDL2
```

run
```
./main
```

似乎什么都没有发生。实际上窗体是一闪而过然后注销了。为什么没有看到窗口呢？因为程序按照顺序执行，执行完毕后，就退出了。