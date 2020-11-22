for((i = 1; i<=50; i++)); do
    echo $i
    input1="../input_files/input"
    input2=$i
    input3=".txt"
    output1="output"
    output2=$i
    output3=".txt"

    input="${input1}${input2}${input3}"
    output="${output1}${output2}${output3}"
    echo $input
    echo $output
    
    ../A < $input > $output
done
