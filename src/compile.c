#include "compile.h"
#include "codegen.h"
#include "ir.h"

#include <stdio.h>
#include <stdlib.h>

int compile(ASTNode *program, char *output_filename) {
    CodeBuffer output = {0};
    code_buffer_init(&output);

    ControlFlowGraph cfg = generate_control_flow_graph(program);
#ifdef DEBUG
    printf("Control Flow Graph:\n");
    for (size_t i = 0; i < cfg.num_blocks; i++) {
        BasicBlock *block = &cfg.blocks[i];
        printf("[BasicBlock %s#%d]\n", block->tag, block->id);
        for (size_t j = 0; j < block->statements.size; j++) {
            ASTNode *statement = (ASTNode *)vector_get(&block->statements, j);
            dump_ast(statement, 4);
        }
    }
#endif

    translate_to_ssa(&cfg);

    code_buffer_write_to_file(&output, output_filename);
    code_buffer_free(&output);
    return 0;
}
