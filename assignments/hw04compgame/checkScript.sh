#!/usr/bin/env bash
#GNU General Public License v3.0
#knedl1k 2023

for i in {1..10}; do
   if [ "$i" -lt 10 ]; then
      i="0$i"
   fi
   input_file="test_data/pub${i}.in"
   expected_output_file="test_data/pub${i}.out"
   actual_output_file="pub${i}.actual.out"

   ./compgame < "$input_file" > "$actual_output_file" 2>&1

   diff_output=$(diff "$actual_output_file" "$expected_output_file")

   if [[ -n $diff_output ]]; then
      echo "Output for $input_file differs from expected output:"
      echo "${diff_output}"
   else
      echo "Output for $input_file matches expected output."
   fi
done
