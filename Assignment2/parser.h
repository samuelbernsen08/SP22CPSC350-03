#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // used for tolower() function

using namespace std;

class Parser {
private: // access specifier
    string s;
    int a_count;
    int b_count;
    int c_count;
    int d_count;
    int e_count;
    int f_count;
    int g_count;
    int h_count;
    int i_count;
    int j_count;
    int k_count;
    int l_count;
    int m_count;
    int n_count;
    int o_count;
    int p_count;
    int q_count;
    int r_count;
    int s_count;
    int t_count;
    int u_count;
    int v_count;
    int w_count;
    int x_count;
    int y_count;
    int z_count;
    int count_num_pairs;
    int count_num_non_alpha;
    int count_num_alpha;
    double average_value;
    int total_alpha_chars;
public: // access specifier

    // function prototypes:
    Parser();
    void num_pairs();
    void check_non_alpha();
    void check_alpha();
    void output();
    void average();
};
