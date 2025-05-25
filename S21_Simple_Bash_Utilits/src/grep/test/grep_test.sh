gcc -Wall -Wextra -Werror ../s21_grep.c -o s21_grep

test_num=0
fail_count=0
succ_count=0
opts=(-e -i -v -c -l -n -h -s -f -iv -vc -ln -nh -hs -ivc -lnh -ncvi -shnl -lcnh -ivclnhse)
texts=("text1.txt" "text2.txt" "text3.txt" "text4.txt" "text1.txt text2.txt" "text2.txt text3.txt" "text1.txt text2.txt" "text1.txt text2.txt text3.txt text4.txt")
regexp_files=(regexp1.txt regexp2.txt regexp3.txt regexp4.txt)
regexps=(nature life technology)

for opt in ${opts[@]}
do
    for text in ${texts[@]}
    do
        if [[ $opt = "-f" ]] 
        then 
            for file in ${regexp_files[@]}
            do 
                echo "Test $test_num:"
                ./s21_grep $opt $file $text > s21_grep_res
                grep $opt $file $text > grep_res
                if [[ $(diff -q grep_res s21_grep_res) ]]
                then 
                    echo "Failed at 's21_grep $opt $file $text'\n"
                    fail_count=$((fail_count + 1))
                else
                    echo "Success\n"
                    succ_count=$((succ_count + 1))
                fi
                test_num=$((test_num + 1))
            done
        else
            for exp in ${regexps[@]}
            do 
                echo "Test $test_num:"
                ./s21_grep $opt $exp $text > s21_grep_res
                grep $opt $exp $text > grep_res
                if [[ $(diff -q grep_res s21_grep_res) ]]
                then 
                    echo "Failed at 's21_grep $opt $exp $text'\n"
                    fail_count=$((fail_count + 1))
                else
                    echo "Success\n"
                    succ_count=$((succ_count + 1))
                fi
                test_num=$((test_num + 1))
            done
        fi
    done
done

if [ $fail_count == 0 ]
    then 
        echo "\nSuccess, $succ_count/$test_num done\n"
    else
        echo "\nFailed, $fail_count/$test_num error(s)\n"
fi

rm -rf grep_res s21_grep_res s21_grep