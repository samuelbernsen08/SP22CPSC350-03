#include "parser.h"
#include <string>

using namespace std;

/*
Parser
Constructor
no parameters
void
*/

Parser::Parser() {
    string user_string;
    s = user_string;
    cout << "Enter in a string: ";
    cin >> s;


    a_count = 0;
    b_count = 0;
    c_count = 0;
    d_count = 0;
    e_count = 0;
    f_count = 0;
    g_count = 0;
    h_count = 0;
    i_count = 0;
    j_count = 0;
    k_count = 0;
    l_count = 0;
    m_count = 0;
    n_count = 0;
    o_count = 0;
    p_count = 0;
    q_count = 0;
    r_count = 0;
    s_count = 0;
    t_count = 0;
    u_count = 0;
    v_count = 0;
    w_count = 0;
    x_count = 0;
    y_count = 0;
    z_count = 0;

    count_num_pairs = 0;
    count_num_non_alpha = 0;
    count_num_alpha = 0;
    average_value = 0.0;
    total_alpha_chars = 0;

}
/*
check_alpha
checks for the number of alphabets in the string and checks for individual characters
no parameters
void
*/


void Parser::check_alpha() {

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            count_num_alpha++;
            tolower(s[i]);
            if (s.at(i) == 'a') {
                a_count++;
            }
            if (s.at(i) == 'b') {
                b_count++;
            }
            if (s.at(i) == 'c') {
                c_count++;
            }
            if (s.at(i) == 'd') {
                d_count++;
            }
            if (s.at(i) == 'e') {
                e_count++;
            }
            if (s.at(i) == 'f') {
                f_count++;
            }
            if (s.at(i) == 'g') {
                g_count++;
            }
            if (s.at(i) == 'h') {
                h_count++;
            }
            if (s.at(i) == 'i') {
                i_count++;
            }
            if (s.at(i) == 'j') {
                j_count++;
            }
            if (s.at(i) == 'k') {
                k_count++;
            }
            if (s.at(i) == 'l') {
                l_count++;
            }
            if (s.at(i) == 'm') {
                m_count++;
            }
            if (s.at(i) == 'n') {
                n_count++;
            }
            if (s.at(i) == 'o') {
                o_count++;
            }
            if (s.at(i) == 'p') {
                p_count++;
            }
            if (s.at(i) == 'q') {
                q_count++;
            }
            if (s.at(i) == 'r') {
                r_count++;
            }
            if (s.at(i) == 's') {
                s_count++;
            }
            if (s.at(i) == 't') {
                t_count++;
            }
            if (s.at(i) == 'u') {
                u_count++;
            }
            if (s.at(i) == 'v') {
                v_count++;
            }
            if (s.at(i) == 'w') {
                w_count++;
            }
            if (s.at(i) == 'x') {
                x_count++;
            }
            if (s.at(i) == 'y') {
                y_count++;
            }
            if (s.at(i) == 'z') {
                z_count++;
            }

        }
    }
}


/*
num_pairs
checks for the number of pairs in the string (consecutive characters)
no parameters
void
*/

void Parser::num_pairs() {
    for (int j = 0; j < s.size(); j++) {
        if (s[j] == s[j + 1]) {
            count_num_pairs++;
        }
    }
}


/*
num_pairs
outputs:
    1. the number of specific characters in the string
    2. the number of total alphabets
    3. the number of non-alphabets
    4. the average value
    5. the number of pairs
to a file called "output.txt"
no parameters
void
*/

void Parser::output() {
    ofstream out_file;
    out_file.open("output.txt");

    out_file << "a:" << a_count << endl;
    out_file << "b:" << b_count << endl;
    out_file << "c:" << c_count << endl;
    out_file << "d:" << d_count << endl;
    out_file << "e:" << e_count << endl;
    out_file << "f:" << f_count << endl;
    out_file << "g:" << g_count << endl;
    out_file << "h:" << h_count << endl;
    out_file << "i:" << i_count << endl;
    out_file << "j:" << j_count << endl;
    out_file << "k:" << k_count << endl;
    out_file << "l:" << l_count << endl;
    out_file << "m:" << m_count << endl;
    out_file << "n:" << n_count << endl;
    out_file << "o:" << o_count << endl;
    out_file << "p:" << p_count << endl;
    out_file << "q:" << q_count << endl;
    out_file << "r:" << r_count << endl;
    out_file << "s:" << s_count << endl;
    out_file << "t:" << t_count << endl;
    out_file << "u:" << u_count << endl;
    out_file << "v:" << v_count << endl;
    out_file << "w:" << w_count << endl;
    out_file << "x:" << x_count << endl;
    out_file << "y:" << y_count << endl;
    out_file << "z:" << z_count << endl;

    out_file << "alphabets:" << count_num_alpha << endl;
    out_file << "non-alphabets: " << count_num_non_alpha << endl;
    out_file << "average:" << average_value << endl;
    out_file << "pairs:" << count_num_pairs << endl;
    out_file.close();

}

/*
check_num_alpha
checks for the number of non-alphabet characters in the string
no parameters
void
*/

void Parser::check_non_alpha() {
    for (int p = 0; p < s.size(); p++) {
        if (!isalpha(s[p])) {
            count_num_non_alpha++;
        }
    }
}

/*
num_pairs
calculates the average value
no parameters
void
*/

void Parser::average() {
    average_value = count_num_alpha / 26.0;
}
