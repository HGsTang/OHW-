# 汪泽旸对于启辰暑假demo的codereview
## 这个程序做的是一个简单的学生信息的管理系统
## *我认为这段代码的不足有以下几小点*  
1. 在多个函数中出现了多次重复使用的代码段，这些本可以用另外一个函数作为替代，引用这个函数会让代码变得短很多。
2. 程序中对于操作的要求过于单一。比如，要删除一个学生的信息，只能通过输入学号来操作，这未免太复杂了，应当有更好的方法才对。
3. 关于程序中函数名、组名这些名称的选用大多有我们组内看得懂的名字，但也少不了一些不明所以的名字，可以将这些名字改一下，程序会更便于他人理解。
