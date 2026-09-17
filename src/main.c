#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "AST.h"
#include "Variables.h"
#include <math.h>

int main() {
    char* input = "value = sqrt(4) + cos(pi/2) + log(e) + max(2/2, 5/3); newvalue = 10 * value + 10 ";

    Table_Manager tm;
    init_table_manager(&tm);
    set_variable(&tm, "pi", M_PI);
    set_variable(&tm, "e", M_E);

    Lexer lexer;
    set_lexer(&lexer, input);

    Token current_token = get_next_token(&lexer);
    ASTNode* root = parse_program(&current_token, &lexer);

    double result = evaluate(root, &tm);
    print_variables(&tm);
    print_ast(root, 0);

    printf("Result : %d\n", result);

    free_ast(root);
    return 0;
}
