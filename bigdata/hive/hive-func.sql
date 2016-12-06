--关系运算
--= : 等值
--<> : 不等于
--<[=] : 小于[或等于]
-->[=] : 大于[或等于]
--op : +,-,*,/,%,&,|,^,~(位取反)

--null
--is null : 空值
--is not null : 不为空值

--like : "_"表示任意单个字符，而字符"%"表示任意数量的字符
--like 'keyword'

--RLIKE : 如果字符串A或者字符串B为NULL，则返回NULL；如果字符串A符合JAVA正则表达式B的正则语法，则为TRUE；否则为FALSE。
--is number
where filed rlike '^\\d+$';
--REGEXP : 同 RLIKE

--逻辑运算
AND, OR, NOT
where NOT 1=2

--四舍五入，返回 BIGINT,返回double类型的整数值部分
round(double)
--返回指定精度的 double 类型，小数点后几位
round(double, int)
--向下取整函数,返回等于或者小于该double变量的最大的整数,BIGINT
floor(double)
--向上取整函数,返回等于或者大于该double变量的最小的整数,BIGINT
ceil(double)
--向上取整函数,同 ceil
ceiling(double)
--随机数函数,返回一个0到1范围内的随机数。如果指定种子seed，则会得到一个稳定的随机数序列
rand(),rand(int seed)
--自然指数函数，返回自然对数e的n次方
exp(double)
--自然对数函数
ln(double),log10(double),log2(double)
--返回以 base 为底的 a 的对数
log(double base,double a)
--返回a的p次幂,与pow功能相同
pow(double a, double p)
--返回a的平方根
sqrt(double a)
--返回a的二进制代码表示,string
bin(BIGINT a)