awk '{
  for (i = 1; i <= NF; ++i)
    a[i] = a[i] ? a[i] FS $i : $i
} END { 
  for (i = 1; a[i] != ""; ++i)
    print a[i]
}' file.txt
