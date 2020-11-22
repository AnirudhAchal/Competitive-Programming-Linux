for((i = 1;; i++)); do
    echo $i
    ./gen $i > int
    ./brute < int > out1
    ./B < int > out2
    diff -w out1 out2 || break
done
