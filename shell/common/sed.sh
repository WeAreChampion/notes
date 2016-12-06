# 删除example文件所有包含test的行
sed '/test/'d file

# 去掉文件中的双引号
sed -i "s/\"//g" file

# 去掉单引号
sed -i "s/'//g" file

# 查看文件的startRow->endRow 行
sed -n 'startRow,endRowp' file

# 截取文件的 startRow->endRow 行到新的文件
sed -n '3,775p' src > dst

# 截取文件到末尾行
sed -n '3,$p' src > dir

# 替换字符
sed ':a;N;$!ba;s/\n/ /g'

# / => \
# 2014/5/10
echo 2014\/5\/10 | sed 's:\\\/:\/:g'
# / => empty
echo "\Naa\a" | sed 's:\\::g'
# com => .com
echo "asd@qqcomas" | sed 's:com:.com:g'
# space => empty
echo "asd @qq com as" | sed 's: ::g'

for p in *.txt; do `sed -i "s/\\N//g" $p`; done

# / => \
# 2014/5/10
echo 2014\/5\/10 | sed 's:\\\/:\/:g'
# / => empty
echo "\Naa\a" | sed 's:\\::g'
# @QQCOM =>@qq.com
echo "@QQCOM" | sed 's:@QQCOM:@qq.com:g'

# \N => empty
for p in *.txt; do cat $p | sed 's:\\\N::g > ../dst/$p'; done
for p in *; do cat $p | sed 's:\\\N::g > $p-trim'; done

# 1019004 =>1020001
echo "1019004" | sed 's:1019004:1020001:g'

for p in grep 'careland' * -r -l; do cat "$p" | sed 's:careland::g' >> "../json_notcareland/$p" ; done

for p in grep -v 'careland' * -r -l; do cp "$p" "../json_notcareland/$p" ; done

cat adsl_relation_all.txt | sed 's:1019004:1020001:g' >> adsl_relation_all_1020001.txt

echo 'asd"-"' | sed 's:"-":"":g'

# replace \t
sed 's/\t//g' src > dst