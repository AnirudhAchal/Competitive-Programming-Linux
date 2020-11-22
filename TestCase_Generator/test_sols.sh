for file in *.txt; do
    echo $file
    ../A < $file > out1
    ../B < $file > out2
    diff -w out1 out2 || break
done

