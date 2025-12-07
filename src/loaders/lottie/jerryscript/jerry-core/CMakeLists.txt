# JerryScript CMakeLists.txt
# Generated based on meson.build structure

cmake_minimum_required(VERSION 3.5)

set(JERRY_CORE_NAME jerry-core)
project(${JERRY_CORE_NAME} CXX)

# Set JerryScript root directory
set(JERRY_CORE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# Include directories
set(JERRY_INCLUDE_DIRS
    ${JERRY_CORE_ROOT}/include
    ${JERRY_CORE_ROOT}
    ${JERRY_CORE_ROOT}/api
    ${JERRY_CORE_ROOT}/ecma/base
    ${JERRY_CORE_ROOT}/ecma/builtin-objects
    ${JERRY_CORE_ROOT}/ecma/builtin-objects/typedarray
    ${JERRY_CORE_ROOT}/ecma/operations
    ${JERRY_CORE_ROOT}/jcontext
    ${JERRY_CORE_ROOT}/jmem
    ${JERRY_CORE_ROOT}/jrt
    ${JERRY_CORE_ROOT}/lit
    ${JERRY_CORE_ROOT}/parser/js
    ${JERRY_CORE_ROOT}/parser/regexp
    ${JERRY_CORE_ROOT}/vm
)

# Source files - API
set(JERRY_API_SOURCES
    ${JERRY_CORE_ROOT}/api/jerryscript.cpp
)

# Source files - ECMA Base
set(JERRY_ECMA_BASE_SOURCES
    ${JERRY_CORE_ROOT}/ecma/base/ecma-alloc.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-errors.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-extended-info.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-gc.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers-collection.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers-conversion.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers-errol.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers-external-pointers.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers-number.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers-string.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers-value.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-helpers.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-init-finalize.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-lcache.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-literal-storage.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-module.cpp
    ${JERRY_CORE_ROOT}/ecma/base/ecma-property-hashmap.cpp
)

# Source files - ECMA Builtin Objects
file(GLOB JERRY_ECMA_BUILTIN_SOURCES
    ${JERRY_CORE_ROOT}/ecma/builtin-objects/*.cpp
)

# Source files - ECMA Builtin Objects TypedArray
file(GLOB JERRY_ECMA_TYPEDARRAY_SOURCES
    ${JERRY_CORE_ROOT}/ecma/builtin-objects/typedarray/*.cpp
)

# Source files - ECMA Operations
file(GLOB JERRY_ECMA_OPERATIONS_SOURCES
    ${JERRY_CORE_ROOT}/ecma/operations/*.cpp
)

# Source files - JContext
set(JERRY_JCONTEXT_SOURCES
    ${JERRY_CORE_ROOT}/jcontext/jcontext.cpp
)

# Source files - JMem
set(JERRY_JMEM_SOURCES
    ${JERRY_CORE_ROOT}/jmem/jmem-allocator.cpp
    ${JERRY_CORE_ROOT}/jmem/jmem-heap.cpp
    ${JERRY_CORE_ROOT}/jmem/jmem-poolman.cpp
)

# Source files - JRT
set(JERRY_JRT_SOURCES
    ${JERRY_CORE_ROOT}/jrt/jrt-fatals.cpp
    ${JERRY_CORE_ROOT}/jrt/jrt-logging.cpp
)

# Source files - Lit
set(JERRY_LIT_SOURCES
    ${JERRY_CORE_ROOT}/lit/lit-char-helpers.cpp
    ${JERRY_CORE_ROOT}/lit/lit-magic-strings.cpp
    ${JERRY_CORE_ROOT}/lit/lit-strings.cpp
)

# Source files - Parser JS
set(JERRY_PARSER_JS_SOURCES
    ${JERRY_CORE_ROOT}/parser/js/byte-code.cpp
    ${JERRY_CORE_ROOT}/parser/js/common.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-lexer.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-parser.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-parser-expr.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-parser-mem.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-parser-module.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-parser-statm.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-parser-tagged-template-literal.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-parser-util.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-scanner.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-scanner-ops.cpp
    ${JERRY_CORE_ROOT}/parser/js/js-scanner-util.cpp
    ${JERRY_CORE_ROOT}/parser/js/parser-errors.cpp
)

# Source files - Parser RegExp
set(JERRY_PARSER_REGEXP_SOURCES
    ${JERRY_CORE_ROOT}/parser/regexp/re-bytecode.cpp
    ${JERRY_CORE_ROOT}/parser/regexp/re-compiler.cpp
    ${JERRY_CORE_ROOT}/parser/regexp/re-parser.cpp
)

# Source files - VM
set(JERRY_VM_SOURCES
    ${JERRY_CORE_ROOT}/vm/opcodes-ecma-arithmetics.cpp
    ${JERRY_CORE_ROOT}/vm/opcodes-ecma-bitwise.cpp
    ${JERRY_CORE_ROOT}/vm/opcodes-ecma-relational-equality.cpp
    ${JERRY_CORE_ROOT}/vm/opcodes.cpp
    ${JERRY_CORE_ROOT}/vm/vm-stack.cpp
    ${JERRY_CORE_ROOT}/vm/vm-utils.cpp
    ${JERRY_CORE_ROOT}/vm/vm.cpp
)

# Combine all sources
set(JERRY_ALL_SOURCES
    ${JERRY_API_SOURCES}
    ${JERRY_ECMA_BASE_SOURCES}
    ${JERRY_ECMA_BUILTIN_SOURCES}
    ${JERRY_ECMA_TYPEDARRAY_SOURCES}
    ${JERRY_ECMA_OPERATIONS_SOURCES}
    ${JERRY_JCONTEXT_SOURCES}
    ${JERRY_JMEM_SOURCES}
    ${JERRY_JRT_SOURCES}
    ${JERRY_LIT_SOURCES}
    ${JERRY_PARSER_JS_SOURCES}
    ${JERRY_PARSER_REGEXP_SOURCES}
    ${JERRY_VM_SOURCES}
)

# Export sources and configuration to parent scope
# This allows the parent CMakeLists.txt to compile jerryscript sources directly into its target
set(JERRY_CORE_SOURCES ${JERRY_ALL_SOURCES} PARENT_SCOPE)
set(JERRY_CORE_INCLUDE_DIRS ${JERRY_INCLUDE_DIRS} PARENT_SCOPE)

# Compile definitions (minimal config for Lottie expressions)
set(JERRY_CORE_COMPILE_DEFINITIONS
    JERRY_BUILTINS=1
    JERRY_PARSER=1
    JERRY_ERROR_MESSAGES=0
    JERRY_EXTERNAL_CONTEXT=0
    JERRY_GLOBAL_HEAP_SIZE=512
    JERRY_GC_LIMIT=0
    JERRY_STACK_LIMIT=0
    JERRY_GC_MARK_LIMIT=8
    JERRY_PROPERTY_HASHMAP=0
    JERRY_LCACHE=1
    JERRY_NUMBER_TYPE_FLOAT64=1
    JERRY_UNICODE_CASE_CONVERSION=0
    JERRY_SNAPSHOT_EXEC=0
    JERRY_SNAPSHOT_SAVE=0
    JERRY_SYSTEM_ALLOCATOR=0
    JERRY_VM_HALT=0
    JERRY_VM_THROW=0
    JERRY_PARSER_DUMP_BYTE_CODE=0
    JERRY_REGEXP_DUMP_BYTE_CODE=0
    PARENT_SCOPE
)

# No external libraries needed - all sources are compiled directly into parent target
# Math functions are typically provided by the standard library automatically
set(JERRY_CORE_LINK_LIBS "" PARENT_SCOPE)

