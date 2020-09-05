.PHONY:all clean
exclude_dirs := Makefile README.md Example
dirs := $(shell ls)
dirs := $(filter-out $(exclude_dirs),$(dirs))
 
all:
	$(foreach N,$(dirs),$(info $(N)))
	
	$(foreach N,$(dirs),make -C $(N);)
clean:
	$(foreach N,$(dirs),make -C $(N) clean;)

#例子1： 过滤函数
#objects=main1.o foo.o main2.o bar.o
#mains=main1.o main2.o 
#$(filter-out $(mains),$(objects))
#实现了去除变量“objects”中“mains”定义的字串（文件名）功能。它的返回值为“foo.o bar.o”

#例子2： 打印变量的值
#1,使用info/warning/error增加调试信息
#方法1: $(info, "here add the debug info")
#           但是此不能打印出.mk的行号
#方法2: $(warning "here add the debug info") 
#方法3: $(error "error: this will stop the compile")
#       这个可以停止当前makefile的编译
#方法4: 打印变量的值
#       $(info $(TARGET_DEVICE) )

#例子3：
#make -C $(N) clean;
#跳转到相应目录然后在执行make语句

#例子4：
#-w的意思是关闭编译时的警告，也就是编译后不显示任何warning
#因为有时在编译之后编译器会显示一些例如数据转换之类的警告，这些警告是我们平时可以忽略的。

#-Wall选项意思是编译后显示所有警告。

#-W选项类似-Wall，会显示警告，但是只显示编译器认为会出现错误的警告。

#例子5：
#PROGS =	TwoSum01 TwoSum02
#CC=g++
#all:	${PROGS}
#
#TwoSum01:	TwoSum01.o
#		${CC}  -o $@ TwoSum01.o 
#TwoSum02:	TwoSum02.o
#		${CC}  -o $@ TwoSum02.o 
		










