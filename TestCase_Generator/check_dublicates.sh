for file1 in *.txt; do
    for file2 in *.txt; do
        cmp --silent $file1 $file2 && echo "{$file1} {$file2}"
    done
done
