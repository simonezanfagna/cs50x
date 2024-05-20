import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) < 3:
        print("missing command-line argument!")
        return

    database_file_CL = sys.argv[1]
    sequence_file_CL = sys.argv[2]

    # TODO: Read database file into a variable

    database_file = []
    with open(database_file_CL) as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            database_file.append(row)

    # TODO: Read DNA sequence file into a variable

    sequence_file = ""
    with open(sequence_file_CL) as file:
        file_reader = file.read()
        sequence_file = file_reader

    # TODO: Find longest match of each STR in DNA sequence

    subsequence = list(database_file[0].keys())
    subsequence.remove(subsequence[0])

    all_match = dict()

    for s in subsequence:
        all_match[s] = longest_match(sequence_file, s)

    # TODO: Check database for matching profiles

    name = ""

    len_all_match = len(all_match)
    count = 0
    for people in database_file:

        if count != len_all_match:
            
            for i in all_match:
                if str(all_match.get(i)) == people.get(i):
                    name = people["name"]
                    count += 1
                else:
                    name = "No match"
                    count = 0
                    break
        else:
            break

    print(name)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
