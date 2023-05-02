    #include "matrix.h"

int main(int argc, char const *argv[]){
    if(argc == 4){
        std::string H_file = argv[1], s_file = argv[2], s_weight = argv[3];
        int weight = stoi(s_weight);
        try{
            Matrix H_st(H_file, "hf");
            Matrix H(H_file, "hf");
            Matrix P_st(H.cols, H.cols, "pst");
            Matrix P(H.cols, H.cols, "pst");
            Matrix U(H.rows, H.rows, "ust");
            Matrix s(s_file,"sf");
            Matrix UI(H.rows,1, "ui");
            Matrix H_buf(H.rows, H.cols, "hf_buf");
            Matrix result(U, H.cols,"res");
            Matrix result_buf(U, H.cols,"res");
            while(true){
                H.IN(H_st);
                P.IN(P_st);
                while(true){
                    P.Random_permutate();
                    H.RM(P, H_buf);
                    H.Last_cols_permutation();
                    H.RREF(U);
                    if(H.Full_rank()) break;
                    else H.First_cols_permutation();
                }
                U.RMM(s, UI);
                if(UI.Ham_weight() == weight)
                {
                    result.TRM(P, result_buf);
                    result.PRINT();
                    break;
                }
            }
        }
        catch(std::bad_alloc){
            std::cout << "new crashed" << std::endl;
        }
    }else{
        std::cout << "error input, argc = " << argc << std::endl;
        std::cout << "must be = 4" << std::endl;
    }
    clock_t end = clock();
    std::cout << " END: " << end << std::endl;    
}

