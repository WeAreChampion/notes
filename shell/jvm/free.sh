# help
free --h
# -b,-k,-m,-g show output in bytes, KB, MB, or GB
# -l show detailed low and high memory statistics
# -o use old format (no -/+buffers/cache line)
# -t display total for RAM + swap
# -s update every [delay] seconds
# -c update [count] times
# -V display version information and exit

# -b:byte,-k:KB,-m:MB,-g:GB
free -m

# 每两秒更新
free -m -s 2