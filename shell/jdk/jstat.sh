# jstat:用于观察Java应用程序运行时信息的工具，可以通过其查看堆信息的详细情况。
# 基本语法:
# jstat -<option> [-t] [-h<lines>] <vmid> [<interval> [<count>]]
# option可由以下值构成
# -class:显示 ClassLoader 的相关信息
# -compiler:显示JIT编译的相关信息
# -GC:显示与GC相关的堆信息
# -gccapacity:显示各个代的容量及使用情况
# -gccause:显示垃圾收集相关信息(同-gcutil)，同时显示最后一次或当前正在发生的垃圾收集的诱发原因
# -gcnew:显示新生代信息
# -gcnewcapacity:显示新生代大小与使用情况
# -gcold:显示老年代和永久代信息
# -gcoldcapacity:显示老年代的大小
# -gcpermcapacity:显示永久代的大小
# -gcutil:显示垃圾收集信息
# -printcompilation:输出JIT编译的方法信息

# -t:可以在输出信息前加上一个Timestamp列，显示程序的运行时间
# -h:可以在周期性数据输出时，输出多少行数据后，跟着输出一个表头信息
# interval:用于指定输出统计数据的周期，单位为毫秒
# count:用于指定一共输出多少次数据

# 输出Java进程 2972 的 ClassLoader 相关信息；每1秒统计一次信息，一共输出2次
#class的输出中，Loaded表示载入了类的数量；Bytes表示载入类的合计大小；Unloaded表示卸载类的数量，第2个Bytes表示卸载类的大小；Time表示在加载和卸载类上所花的时间
jstat -class -t 2972 1000 2

# 查看Java进程 2972 的JIT编译的信息
#Compiled表示编译任务执行的次数；Failed表示编译失败的次数；Invalid表示编译不可用的次数；Time表示编译的总耗时；FailedType表示最后一次编译失败的类型；FailedMethod表示最后一次编译失败的类名和方法名。
jstat -compiler -t 2972

# 显示与GC相关的堆信息的输出
# S0C:s0(from)区的大小;S1C:s1(to)区的大小;S0U:s0(from)已使用的空间(KB);S1U:s1(to)已使用的空间(KB);
# EC:eden区的大小(KB);EU:eden区已使用的空间(KB);OC:老年代大小(KB);OU:老年代已使用的空间(KB)
# PC:永久区大小(KB);PU:永久区已使用的空间(KB);YGC:新生代GC次数;YGCT:新生代GC耗时;
# FGC:FullGC次数;FGCT:FullGC耗时;GCT:GC总耗时
jstat -GC 2972

# 与-GC相比，不仅输出了各个代的当前大小，也包含了各个代的最大值和最小值
# NGCMN:新生代最小值(KB);NGCMX:新生代最大值(KB);NGC:当前新生代大小(KB)
# OGCMN:老年代最小值(KB);OGCMX:老年代最大值(KB);PGCMN:永久代最小值(KB);PGCMX:永久代最大值(KB)
jstat -gccapacity 2972

# 显示最近一次GC的原因以及当前GC的原因
# LGCC:上传GC的原因;GCC:当前GC的原因
jstat -gccause 2972

# 查看新生代的一些详细信息
# TT:新生代对象晋升到老年代对象的年龄;MTT:新生代对象晋升到老年代对象的年龄最大值;DSS:所需的survivor区大小
jstat -gcnew 2972

# 输出新生代详细各个区的大小信息
# S0CMX:s0(from)区的最大值(KB);s1CMX:s1(to)区的最大值(KB);ECMX:eden区的最大值(KB)
jstat -gcnewcapacity

# 展现老年代的GC概况
jstat -gcold 2972

# 老年代的容量信息
jstat -gcoldcapacity 2972

# 永久区的使用情况
jstat -gcpermcapacity 2972

# 展示GC相关信息
# S0:s0区使用的百分比;S1:s1区使用的百分比;E:eden区使用的百分比;O:Old区使用的百分比;P:永久区使用的百分比
jstat -gcutil 2972