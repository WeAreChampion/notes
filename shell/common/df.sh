# df : system parted info
# show with bytes
df

# show with K,M,G
df -h

# -T : 分区是哪种文件系统
# -Th : -T -h
# -Tha : -T -h -a
# show system all parted info
df -Tha

# 只看硬盘中 FAT32 分区的情况, using -t
df -Th -t vfat

# 看除 FAT32 分区以外的其它分区
df -Th -x vfat
