cmake_minimum_required(VERSION 3.10)
project(p101_unix
        VERSION 0.0.1
        DESCRIPTION ""
        LANGUAGES C)

message(STATUS "Compiler being used: ${CMAKE_C_COMPILER}")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Source files for the library
set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/err.c
        ${CMAKE_SOURCE_DIR}/src/execinfo.c
        ${CMAKE_SOURCE_DIR}/src/fstab.c
        ${CMAKE_SOURCE_DIR}/src/getopt.c
        ${CMAKE_SOURCE_DIR}/src/ifaddrs.c
        ${CMAKE_SOURCE_DIR}/src/resolv.c
        ${CMAKE_SOURCE_DIR}/src/stdlib.c
        ${CMAKE_SOURCE_DIR}/src/ttyent.c
        ${CMAKE_SOURCE_DIR}/src/arpa/nameser.c
        ${CMAKE_SOURCE_DIR}/src/net/ethernet.c
        ${CMAKE_SOURCE_DIR}/src/sys/mount.c
        ${CMAKE_SOURCE_DIR}/src/sys/timex.c
)

# Define the list of header files to install
set(HEADER_LIST
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_err.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_execinfo.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_fstab.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_getopt.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_ifaddrs.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_resolv.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_stdlib.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/p101_ttyent.h
)

set(HEADER_LIST_ARPA
        ${CMAKE_SOURCE_DIR}/include/p101_unix/arpa/p101_nameser.h
)

set(HEADER_LIST_NET
        ${CMAKE_SOURCE_DIR}/include/p101_unix/net/p101_ethernet.h
)

set(HEADER_LIST_SYS
        ${CMAKE_SOURCE_DIR}/include/p101_unix/sys/p101_mount.h
        ${CMAKE_SOURCE_DIR}/include/p101_unix/sys/p101_timex.h
)

# Build the shared library
add_library(p101_unix SHARED ${SOURCES})

target_include_directories(p101_unix PRIVATE /usr/local/include)
target_link_directories(p101_unix PRIVATE /usr/local/lib)
target_link_directories(p101_unix PRIVATE /usr/local/lib64)

# Enable UBSan checks
target_compile_options(p101_unix PRIVATE -fsanitize=undefined)
target_link_libraries(p101_unix PRIVATE -fsanitize=undefined)

# Include directories (if needed)
target_include_directories(p101_unix PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link libraries (if needed)
target_link_libraries(p101_unix PRIVATE iconv)
target_link_libraries(p101_unix PRIVATE p101_error)
target_link_libraries(p101_unix PRIVATE p101_env)
target_link_libraries(p101_unix PRIVATE p101_c)

# Common compiler flags
set(STANDARD_FLAGS
        -D_POSIX_C_SOURCE=200809L
        -D_XOPEN_SOURCE=700
        -D_GNU_SOURCE
        #        -D_DEFAULT_SOURCE
        -D_DARWIN_C_SOURCE
        #        -D__BSD_VISIBLE
        -Werror
)

# Compiler warning flags
set(WARNING_FLAGS
        -pedantic-errors
        -Waddress
        -Waggregate-return
        -Wall
        -Walloc-zero
        -Walloca
        -Warith-conversion
        -Warray-bounds
        -Wattribute-alias=2
        -Wbad-function-cast
        -Wbool-compare
        -Wbool-operation
        -Wcast-align
        -Wcast-align=strict
        -Wcast-function-type
        -Wcast-qual
        -Wchar-subscripts
        -Wclobbered
        -Wcomment
        -Wconversion
        -Wdangling-else
        -Wdangling-pointer
        -Wdangling-pointer=2
        -Wdate-time
        -Wdeclaration-after-statement
        -Wdisabled-optimization
        -Wdouble-promotion
        -Wduplicated-branches
        -Wduplicated-cond
        -Wempty-body
        -Wenum-compare
        -Wenum-conversion
        -Wenum-int-mismatch
        -Wexpansion-to-defined
        -Wextra
        -Wfatal-errors
        -Wflex-array-member-not-at-end
        -Wfloat-conversion
        -Wfloat-equal
        -Wformat
        -Wformat-overflow=2
        -Wformat-security
        -Wformat-signedness
        -Wformat-truncation=2
        -Wformat-y2k
        -Wformat=2
        -Wframe-address
        -Wignored-qualifiers
        -Wimplicit
        -Wimplicit-fallthrough
        -Wimplicit-fallthrough=3
        -Winfinite-recursion
        -Winit-self
        -Winline
        -Wint-in-bool-context
        -Winvalid-pch
        -Winvalid-utf8
        -Wjump-misses-init
        -Wlogical-not-parentheses
        -Wlogical-op
        -Wmain
        -Wmaybe-uninitialized
        -Wmemset-elt-size
        -Wmemset-transposed-args
        -Wmisleading-indentation
        -Wmissing-attributes
        -Wmissing-braces
        -Wmissing-declarations
        -Wmissing-field-initializers
        -Wmissing-format-attribute
        -Wmissing-include-dirs
        -Wmissing-noreturn
        -Wmissing-parameter-type
        -Wmissing-prototypes
        -Wmissing-variable-declarations
        -Wmultistatement-macros
        -Wnested-externs
        -Wnull-dereference
        -Wold-style-declaration
        -Wold-style-definition
        -Wopenacc-parallelism
        -Wopenmp-simd
        -Woverlength-strings
        -Wpacked
        -Wpacked-not-aligned
        -Wparentheses
        -Wpedantic
        -Wpointer-arith
        -Wpointer-sign
        -Wredundant-decls
        -Wrestrict
        -Wreturn-type
        -Wsequence-point
        -Wshadow
        -Wshadow=compatible-local
        -Wshadow=global
        -Wshadow=local
        -Wshift-negative-value
        -Wshift-overflow=2
        -Wsign-compare
        -Wsign-conversion
        -Wsizeof-array-div
        -Wsizeof-pointer-div
        -Wsizeof-pointer-memaccess
        -Wstack-protector
        -Wstrict-aliasing
        -Wstrict-aliasing=3
        -Wstrict-flex-arrays
        -Wstrict-prototypes
        -Wstring-compare
        -Wswitch
        -Wswitch-default
        -Wswitch-enum
        -Wsync-nand
        -Wtautological-compare
        -Wtrampolines
        -Wtrigraphs
        -Wtrivial-auto-var-init
        -Wtsan
        -Wtype-limits
        -Wundef
        -Wuninitialized
        -Wunknown-pragmas
        -Wunused
        -Wunused-but-set-parameter
        -Wunused-but-set-variable
        -Wunused-const-variable
        -Wunused-const-variable=2
        -Wunused-function
        -Wunused-label
        -Wunused-local-typedefs
        -Wunused-macros
        -Wunused-parameter
        -Wunused-value
        -Wunused-variable
        -Wvariadic-macros
        -Wvector-operation-performance
        -Wvla
        -Wvolatile-register-var
        -Wwrite-strings
        -Wxor-used-as-pow
        -Wzero-length-bounds
        -Wbidi-chars=unpaired,ucn
        -Wc++-compat
        -W
        -Wabsolute-value
        -Waddress-of-packed-member
        -Waddress-of-temporary
        -Waix-compat
        -Walign-mismatch
        -Walloca-with-align-alignof
        -Walways-inline-coroutine
        -Wambiguous-ellipsis
        -Wambiguous-macro
        -Wambiguous-member-template
        -Wambiguous-reversed-operator
        -Wanalyzer-incompatible-plugin
        -Wanon-enum-enum-conversion
        -Wanonymous-pack-parens
        -Warc
        -Warc-bridge-casts-disallowed-in-nonarc
        -Warc-maybe-repeated-use-of-weak
        -Warc-non-pod-memaccess
        -Warc-performSelector-leaks
        -Warc-repeated-use-of-weak
        -Warc-retain-cycles
        -Warc-unsafe-retained-assign
        -Wargument-outside-range
        -Wargument-undefined-behaviour
        -Warray-bounds-pointer-arithmetic
        -Warray-parameter
        -Wasm
        -Wasm-operand-widths
        -Wassign-enum
        -Wassume
        -Wat-protocol
        -Watimport-in-framework-header
        -Watomic-access
        -Watomic-alignment
        -Watomic-implicit-seq-cst
        -Watomic-memory-ordering
        -Watomic-properties
        -Watomic-property-with-user-defined-accessor
        -Wattribute-packed-for-bitfield
        -Wattribute-warning
        -Wattributes
        -Wauto-disable-vptr-sanitizer
        -Wauto-import
        -Wauto-storage-class
        -Wauto-var-id
        -Wavailability
        -Wavr-rtlib-linking-quirks
        -Wbackend-plugin
        -Wbackslash-newline-escape
        -Wbinary-literal
        -Wbind-to-temporary-copy
        -Wbinding-in-condition
        -Wbit-int-extension
        -Wbitfield-constant-conversion
        -Wbitfield-enum-conversion
        -Wbitfield-width
        -Wbitwise-conditional-parentheses
        -Wbitwise-instead-of-logical
        -Wbitwise-op-parentheses
        -Wblock-capture-autoreleasing
        -Wbool-conversion
        -Wbool-conversions
        -Wbool-operation
        -Wbraced-scalar-init
        -Wbranch-protection
        -Wbridge-cast
        -Wbuiltin-assume-aligned-alignment
        -Wbuiltin-macro-redefined
        -Wbuiltin-memcpy-chk-size
        -Wbuiltin-requires-header
        -Wc11-extensions
        -Wc23-compat
        -Wc23-extensions
        -Wc2x-compat
        -Wc2x-extensions
        -Wc99-compat
        -Wc99-designator
        -Wc99-extensions
        -Wcalled-once-parameter
        -Wcast-calling-convention
        -Wcast-function-type-strict
        -Wcast-of-sel-type
        -Wcast-qual-unrelated
        -WCFString-literal
        -Wchar-align
        -WCL4
        -Wclang-cl-pch
        -Wclass-varargs
        -Wcmse-union-leak
        -Wcomma
        -Wcomments
        -Wcompletion-handler
        -Wcomplex-component-init
        -Wcompound-token-split
        -Wcompound-token-split-by-macro
        -Wcompound-token-split-by-space
        -Wconditional-type-mismatch
        -Wconditional-uninitialized
        -Wconfig-macros
        -Wconstant-conversion
        -Wconstant-evaluated
        -Wconstant-logical-operand
        -Wconstexpr-not-const
        -Wconsumed
        -Wcoro-non-aligned-allocation-function
        -Wcoroutine
        -Wcoroutine-missing-unhandled-exception
        -Wcovered-switch-default
        -Wcpp
        -Wcstring-format-directive
        -Wctu
        -Wcuda-compat
        -Wcustom-atomic-properties
        -Wcxx-attribute-extension
        -Wdangling
        -Wdangling-field
        -Wdangling-gsl
        -Wdangling-initializer-list
        -Wdealloc-in-category
        -Wdebug-compression-unavailable
        -Wdefaulted-function-deleted
        -Wdelegating-ctor-cycles
        -Wdelimited-escape-sequence-extension
        -Wdeprecate-lax-vec-conv-all
        -Wdeprecated
        -Wdeprecated-altivec-src-compat
        -Wdeprecated-anon-enum-enum-conversion
        -Wdeprecated-array-compare
        -Wdeprecated-attributes
        -Wdeprecated-builtins
        -Wdeprecated-comma-subscript
        -Wdeprecated-coroutine
        -Wdeprecated-declarations
        -Wdeprecated-dynamic-exception-spec
        -Wdeprecated-enum-compare
        -Wdeprecated-enum-compare-conditional
        -Wdeprecated-implementations
        -Wdeprecated-increment-bool
        -Wdeprecated-literal-operator
        -Wdeprecated-non-prototype
        -Wdeprecated-pragma
        -Wdeprecated-redundant-constexpr-static-def
        -Wdeprecated-register
        -Wdeprecated-static-analyzer-flag
        -Wdeprecated-this-capture
        -Wdeprecated-type
        -Wdeprecated-volatile
        -Wdeprecated-writable-strings
        -Wdirect-ivar-access
        -Wdisabled-macro-expansion
        -Wdiscard-qual
        -Wdistributed-object-modifiers
        -Wdiv-by-zero
        -Wdivision-by-zero
        -Wdll-attribute-on-redeclaration
        -Wdllexport-explicit-instantiation-decl
        -Wdllimport-static-field-def
        #        -Wdocumentation
        #        -Wdocumentation-deprecated-sync
        #        -Wdocumentation-html
        #        -Wdocumentation-pedantic
        #        -Wdocumentation-unknown-command
        -Wdollars-in-identifier-extension
        -Wdollar-in-identifier-extension
        -Wdtor-name
        -Wdtor-typedef
        -Wduplicate-decl-specifier
        -Wduplicate-enum
        -Wduplicate-method-arg
        -Wduplicate-method-match
        -Wduplicate-protocol
        -Wdxil-validation
        -Wdynamic-class-memaccess
        -Wdynamic-exception-spec
        -Weager-load-cxx-named-modules
        -Welaborated-enum-base
        -Welaborated-enum-class
        -Wembedded-directive
        -Wempty-decomposition
        -Wempty-init-stmt
        -Wempty-translation-unit
        -Wencode-type
        -Wendif-labels
        -Wenum-compare-conditional
        -Wenum-compare-switch
        -Wenum-constexpr-conversion
        -Wenum-enum-conversion
        -Wenum-float-conversion
        -Wenum-too-large
        -Wexcess-initializers
        -Wexcessive-regsave
        -Wexit-time-destructors
        -Wexperimental-header-units
        -Wexplicit-initialize-call
        -Wexplicit-ownership-type
        -Wexport-unnamed
        -Wextern-c-compat
        -Wextern-initializer
        -Wextra-qualification
        -Wextra-semi-stmt
        -Wextra-tokens
        -Wfinal-dtor-non-final-class
        -Wfinal-macro
        -Wfixed-enum-extension
        -Wfixed-point-overflow
        -Wflag-enum
        -Wflexible-array-extensions
        -Wfloat-overflow-conversion
        -Wfloat-zero-conversion
        -Wfor-loop-analysis
        -Wformat-extra-args
        -Wformat-insufficient-args
        -Wformat-invalid-specifier
        -Wformat-non-iso
        -Wformat-nonliteral
        -Wformat-pedantic
        -Wformat-type-confusion
        -Wformat-zero-length
        -Wfortify-source
        -Wfour-char-constants
        -Wframework-include-private-from-public
        -Wfree-nonheap-object
        -Wfunction-multiversion
        -Wfuse-ld-path
        -Wfuture-attribute-extensions
        -Wfuture-compat
        -Wgcc-compat
        -Wgeneric-type-extension
        -Wglobal-constructors
        -Wglobal-isel
        -Wgnu
        -Wgnu-alignof-expression
        -Wgnu-anonymous-struct
        -Wgnu-array-member-paren-init
        -Wgnu-auto-type
        -Wgnu-binary-literal
        -Wgnu-case-range
        -Wgnu-complex-integer
        -Wgnu-compound-literal-initializer
        -Wgnu-conditional-omitted-operand
        -Wgnu-designator
        -Wgnu-empty-initializer
        -Wgnu-empty-struct
        -Wgnu-flexible-array-initializer
        -Wgnu-flexible-array-union-member
        -Wgnu-folding-constant
        -Wgnu-imaginary-constant
        -Wgnu-include-next
        -Wgnu-inline-cpp-without-extern
        -Wgnu-label-as-value
        -Wgnu-line-marker
        -Wgnu-null-pointer-arithmetic
        -Wgnu-offsetof-extensions
        -Wgnu-pointer-arith
        -Wgnu-redeclared-enum
        -Wgnu-statement-expression
        -Wgnu-statement-expression-from-macro-expansion
        -Wgnu-static-float-init
        -Wgnu-string-literal-operator-template
        -Wgnu-union-cast
        -Wgnu-variable-sized-type-not-at-end
        -Wgnu-zero-line-directive
        -Wgnu-zero-variadic-macro-arguments
        -Wgpu-maybe-wrong-side
        -Wheader-guard
        -Wheader-hygiene
        -Whip-omp-target-directives
        -Whip-only
        -Whlsl-extensions
        -Widiomatic-parentheses
        -Wignored-attributes
        -Wignored-availability-without-sdk-settings
        -Wignored-optimization-argument
        -Wignored-pragma-intrinsic
        -Wignored-pragma-optimize
        -Wignored-pragmas
        -Wignored-reference-qualifiers
        -Wimplicit-atomic-properties
        -Wimplicit-const-int-float-conversion
        -Wimplicit-conversion-floating-point-to-bool
        -Wimplicit-exception-spec-mismatch
        -Wimplicit-fallthrough-per-function
        -Wimplicit-fixed-point-conversion
        -Wimplicit-float-conversion
        -Wimplicit-function-declaration
        -Wimplicit-int
        -Wimplicit-int-conversion
        -Wimplicit-int-float-conversion
        -Wimplicit-retain-self
        -Wimplicitly-unsigned-literal
        -Wimport
        -Wimport-preprocessor-directive-pedantic
        -Winclude-next-absolute-path
        -Winclude-next-outside-header
        -Wincompatible-exception-spec
        -Wincompatible-function-pointer-types
        -Wincompatible-function-pointer-types-strict
        -Wincompatible-library-redeclaration
        -Wincompatible-ms-pragma-section
        -Wincompatible-ms-struct
        -Wincompatible-pointer-types
        -Wincompatible-pointer-types-discards-qualifiers
        -Wincompatible-property-type
        -Wincompatible-sysroot
        -Wincomplete-framework-module-declaration
        -Wincomplete-implementation
        -Wincomplete-module
        -Wincomplete-setjmp-declaration
        -Wincomplete-umbrella
        -Winconsistent-dllimport
        -Winconsistent-missing-destructor-override
        -Winconsistent-missing-override
        -Wincrement-bool
        -WIndependentClass-attribute
        -Winitializer-overrides
        -Winjected-class-name
        -Winline-asm
        -Winline-namespace-reopened-noninline
        -Winline-new-delete
        -Winstantiation-after-specialization
        -Wint-conversion
        -Wint-conversions
        -Wint-to-pointer-cast
        -Wint-to-void-pointer-cast
        -Winteger-overflow
        -Winvalid-command-line-argument
        -Winvalid-constexpr
        -Winvalid-iboutlet
        -Winvalid-initializer-from-system-header
        -Winvalid-ios-deployment-target
        -Winvalid-no-builtin-names
        -Winvalid-noreturn
        -Winvalid-or-nonexistent-directory
        -Winvalid-partial-specialization
        -Winvalid-pp-token
        -Winvalid-source-encoding
        -Winvalid-static-assert-message
        -Winvalid-token-paste
        -Winvalid-unevaluated-string
        -Wjump-seh-finally
        -Wkeyword-compat
        -Wkeyword-macro
        -Wknr-promoted-parameter
        -Wlanguage-extension-token
        -Wlarge-by-value-copy
        -Wliblto
        -Wlinker-warnings
        -Wliteral-conversion
        -Wliteral-range
        -Wlocal-type-template-args
        -Wlogical-op-parentheses
        -Wloop-analysis
        -Wmacro-redefined
        -Wmain-return-type
        -Wmalformed-warning-check
        -Wmany-braces-around-scalar-init
        -Wmathematical-notation-identifier-extension
        -Wmax-tokens
        -Wmax-unsigned-zero
        -Wmemsize-comparison
        -Wmethod-signatures
        -Wmisexpect
        -Wmismatched-parameter-types
        -Wmismatched-return-types
        -Wmissing-constinit
        -Wmissing-exception-spec
        -Wmissing-method-return-type
        -Wmissing-multilib
        -Wmissing-noescape
        -Wmissing-noreturn
        -Wmissing-prototype-for-cc
        -Wmissing-selector-name
        -Wmissing-sysroot
        -Wmisspelled-assumption
        -Wmodule-conflict
        -Wmodule-file-config-mismatch
        -Wmodule-file-extension
        -Wmodule-import-in-extern-c
        -Wmodules-ambiguous-internal-linkage
        -Wmodules-import-nested-redundant
        -Wmost
        -Wmove
        -Wmsvc-include
        -Wmsvc-not-found
        -Wmulti-gpu
        -Wmultichar
        -Wmultiple-move-vbase
        -Wnarrowing
        -Wnested-anon-types
        -Wnew-returns-null
        -Wnewline-eof
        -Wnsconsumed-mismatch
        -WNSObject-attribute
        -Wnsreturns-mismatch
        -Wnull-arithmetic
        -Wnull-character
        -Wnull-conversion
        -Wnull-pointer-arithmetic
        -Wnull-pointer-subtraction
        -Wnullability
        -Wnullability-completeness
        -Wnullability-completeness-on-arrays
        -Wnullability-declspec
        -Wnullability-extension
        -Wnullability-inferred-on-nested-type
        -Wnullable-to-nonnull-conversion
        -Wodr
        -Wopencl-unsupported-rgba
        -Wopenmp
        -Wopenmp-51-extensions
        -Wopenmp-clauses
        -Wopenmp-extensions
        -Wopenmp-loop-form
        -Wopenmp-mapping
        -Wopenmp-target
        -Wopenmp-target-exception
        -Woption-ignored
        -Wordered-compare-function-pointers
        -Wout-of-line-declaration
        -Wout-of-scope-function
        -Wover-aligned
        -Woverflow
        -Woverloaded-shift-op-parentheses
        -Woverride-init
        -Woverride-module
        -Woverriding-method-mismatch
        -Woverriding-option
        -Wpacked-non-pod
        -Wparentheses-equality
        -Wpartial-availability
        -Wpass-failed
        -Wpch-date-time
        -Wpedantic-core-features
        -Wpedantic-macros
        -Wpointer-bool-conversion
        -Wpointer-compare
        -Wpointer-integer-compare
        -Wpointer-to-enum-cast
        -Wpointer-to-int-cast
        -Wpointer-type-mismatch
        -Wpotentially-direct-selector
        -Wpotentially-evaluated-expression
        -Wpragma-clang-attribute
        -Wpragma-once-outside-header
        -Wpragma-pack
        -Wpragma-pack-suspicious-include
        -Wpragma-system-header-outside-header
        -Wpragmas
        -Wpre-c23-compat
        -Wpre-c23-compat-pedantic
        -Wpre-c2x-compat
        -Wpre-c2x-compat-pedantic
        -Wpre-openmp-51-compat
        -Wpredefined-identifier-outside-function
        -Wprivate-extern
        -Wprivate-header
        -Wprivate-module
        -Wprofile-instr-missing
        -Wprofile-instr-out-of-date
        -Wprofile-instr-unprofiled
        -Wproperty-access-dot-syntax
        -Wproperty-attribute-mismatch
        -Wprotocol-property-synthesis-ambiguity
        -Wpsabi
        -Wqualified-void-return-type
        -Wquoted-include-in-framework-header
        -Wrange-loop-analysis
        -Wrange-loop-bind-reference
        -Wread-modules-implicitly
        -Wread-only-types
        -Wreadonly-iboutlet-property
        -Wreceiver-expr
        -Wreceiver-forward-class
        -Wredeclared-class-member
        -Wredundant-consteval-if
        -Wredundant-parens
        -Wreinterpret-base-class
        -Wreorder-ctor
        -Wreorder-init-list
        -Wrequires-super-attribute
        -Wreserved-id-macro
        -Wreserved-identifier
        -Wreserved-macro-identifier
        -Wreserved-module-identifier
        -Wreserved-user-defined-literal
        -Wrestrict-expansion
        -Wretained-language-linkage
        -Wreturn-local-addr
        -Wreturn-stack-address
        -Wreturn-std-move
        -Wreturn-type-c-linkage
        -Wrewrite-not-bool
        -Wrtti
        -Wsarif-format-unstable
        -Wsection
        -Wselector-type-mismatch
        -Wself-assign
        -Wself-assign-field
        -Wself-assign-overloaded
        -Wself-move
        -Wsemicolon-before-method-body
        -Wsentinel
        -Wserialized-diagnostics
        -Wshadow-all
        -Wshadow-field
        -Wshadow-field-in-constructor
        -Wshadow-field-in-constructor-modified
        -Wshadow-uncaptured-local
        -Wshift-count-negative
        -Wshift-count-overflow
        -Wshift-op-parentheses
        -Wshift-overflow
        -Wshift-sign-overflow
        -Wshorten-64-to-32
        -Wsigned-enum-bitfield
        -Wsigned-unsigned-wchar
        -Wsingle-bit-bitfield-constant-conversion
        -Wsizeof-array-argument
        -Wsizeof-array-decay
        -Wslash-u-filename
        -Wslh-asm-goto
        -Wsometimes-uninitialized
        -Wsource-mgr
        -Wsource-uses-openmp
        -Wspir-compat
        -Wspirv-compat
        -Wstack-exhausted
        -Wstatic-float-init
        -Wstatic-in-inline
        -Wstatic-inline-explicit-instantiation
        -Wstatic-local-in-inline
        -Wstatic-self-init
        -Wstdlibcxx-not-found
        -Wstrict-potentially-direct-selector
        -Wstring-concatenation
        -Wstring-conversion
        -Wstring-plus-char
        -Wstring-plus-int
        -Wstrlcpy-strlcat-size
        -Wstrncat-size
        -Wsuggest-attribute=const
        -Wsuggest-attribute=malloc
        -Wsuggest-attribute=noreturn
        -Wsuggest-attribute=pure
        -Wsuggest-destructor-override
        -Wsuper-class-method-mismatch
        -Wsuspicious-bzero
        -Wsuspicious-memaccess
        -Wswift-name-attribute
        -Wswitch-bool
        -Wsync-alignment
        -Wsync-fetch-and-nand-semantics-changed
        -Wtarget-clones-mixed-specifiers
        -Wtautological-bitwise-compare
        -Wtautological-constant-compare
        -Wtautological-constant-in-range-compare
        -Wtautological-constant-out-of-range-compare
        -Wtautological-negation-compare
        -Wtautological-overlap-compare
        -Wtautological-pointer-compare
        -Wtautological-type-limit-compare
        -Wtautological-undefined-compare
        -Wtautological-unsigned-char-zero-compare
        -Wtautological-unsigned-enum-zero-compare
        -Wtautological-unsigned-zero-compare
        -Wtautological-value-range-compare
        -Wtcb-enforcement
        -Wtentative-definition-incomplete-type
        -Wthread-safety
        -Wthread-safety-analysis
        -Wthread-safety-attributes
        -Wthread-safety-beta
        -Wthread-safety-negative
        -Wthread-safety-precise
        -Wthread-safety-reference
        -Wthread-safety-verbose
        -Wtype-safety
        -Wtypedef-redefinition
        -Wtypename-missing
        -Wunable-to-open-stats-file
        -Wunaligned-access
        -Wunaligned-qualifier-implicit-cast
        -Wunavailable-declarations
        -Wundef-prefix
        -Wundefined-bool-conversion
        -Wundefined-func-template
        -Wundefined-inline
        -Wundefined-internal
        -Wundefined-internal-type
        -Wundefined-reinterpret-cast
        -Wundefined-var-template
        -Wunderaligned-exception-object
        -Wunevaluated-expression
        -Wunguarded-availability
        -Wunguarded-availability-new
        -Wunicode
        -Wunicode-homoglyph
        -Wunicode-whitespace
        -Wunicode-zero-width
        -Wuninitialized-const-reference
        -Wunknown-argument
        -Wunknown-assumption
        -Wunknown-attributes
        -Wunknown-cuda-version
        -Wunknown-directives
        -Wunknown-escape-sequence
        -Wunknown-sanitizers
        -Wno-unknown-warning-option
        -Wunnamed-type-template-args
        -Wunneeded-internal-declaration
        -Wunneeded-member-function
        -Wunqualified-std-cast-call
        -Wunreachable-code
        -Wunreachable-code-aggressive
        -Wunreachable-code-break
        -Wunreachable-code-fallthrough
        -Wunreachable-code-generic-assoc
        -Wunreachable-code-loop-increment
        -Wunreachable-code-return
        -Wunsequenced
        -Wunsupported-abi
        -Wunsupported-abs
        -Wunsupported-availability-guard
        -Wunsupported-cb
        -Wunsupported-dll-base-class-template
        -Wunsupported-floating-point-opt
        -Wunsupported-friend
        -Wunsupported-gpopt
        -Wunsupported-nan
        -Wunsupported-target-opt
        -Wunsupported-visibility
        -Wunusable-partial-specialization
        -Wunused-argument
        -Wno-unused-command-line-argument   # something is wrong with clang
        #        -Wunused-command-line-argument   # something is wrong with clang
        -Wunused-comparison
        -Wunused-exception-parameter
        -Wunused-getter-return-value
        -Wunused-lambda-capture
        -Wunused-local-typedef
        -Wunused-member-function
        -Wunused-private-field
        -Wunused-property-ivar
        -Wunused-result
        -Wunused-template
        -Wunused-volatile-lvalue
        -Wused-but-marked-unused
        -Wuser-defined-literals
        -Wuser-defined-warnings
        -Wvarargs
        -Wvec-elem-size
        -Wvector-conversion
        -Wvector-conversions
        -Wvisibility
        -Wvla-extension
        -Wvoid-pointer-to-enum-cast
        -Wvoid-pointer-to-int-cast
        -Wvoid-ptr-dereference
        -Wvolatile-register-var
        -Wwasm-exception-spec
        -Wweak-template-vtables
        -Wweak-vtables
        -Wwritable-strings
        -Wzero-length-array
        -Wc++-compat
        #    -Wabi
        # these need special support for the makefile      -W#pragma-messages
        # these need special support for the makefile      -W#warnings
)

# Compiler analyzer flags
set(ANALYZER_FLAGS
        # this needs to be handled better        --analyze
        --analyzer
        -Xanalyzer
        -fanalyzer
        -fanalyzer-transitivity
        -fanalyzer-verbosity=3
        -Wno-analyzer-too-complex
        -Wno-analyzer-fd-leak
)

# Compiler debugging flags
set(DEBUG_FLAGS
        -g3
        -ggdb
        -fvar-tracking
        -fvar-tracking-assignments
        -gcolumn-info
)

# Compiler sanitizer flags
set(SANITIZER_FLAGS
        -fsanitize=address
        -fsanitize=pointer-compare
        -fsanitize=pointer-subtract
        -fsanitize=leak
        -fsanitize=undefined
        -fsanitize=shift
        -fsanitize=shift-exponent
        -fsanitize=shift-base
        -fsanitize=integer-divide-by-zero
        -fsanitize=unreachable
        -fsanitize=vla-bound
        -fsanitize=null
        -fsanitize=signed-integer-overflow
        -fsanitize=bounds
        -fsanitize=bounds-strict
        -fsanitize=alignment
        #    -fsanitize=object-size
        -fsanitize=float-divide-by-zero
        -fsanitize=float-cast-overflow
        -fsanitize=nonnull-attribute
        -fsanitize=returns-nonnull-attribute
        -fsanitize=bool
        -fsanitize=enum
        -fsanitize=pointer-overflow
        -fsanitize=builtin
        -fsanitize-address-use-after-scope
        #        -fcf-protection=full # M1 (and I assume M2) Mac does not support this
        -fharden-compares
        -fharden-conditional-branches
        -fstack-protector-all
        -fstack-clash-protection
        -fharden-control-flow-redundancy
        -fno-delete-null-pointer-checks
        -fno-omit-frame-pointer
        #        -fsanitize-coverage=trace-pc
        #        -fsanitize-coverage=trace-cmp
        #        -finstrument-functions
)

include(CheckCCompilerFlag)

# Function to check and add compiler flags if supported
function(add_compile_options_if_supported flag_list category flag_list_variable)
    message(STATUS "Checking ${category} flags...")
    foreach(FLAG IN LISTS ${flag_list})
        string(REPLACE "-" "" FLAG_NO_HYPHEN ${FLAG})
        include(CheckCCompilerFlag)
        message(STATUS "Checking if ${FLAG} is supported...")
        check_c_compiler_flag(${FLAG} COMPILER_SUPPORTS_${FLAG_NO_HYPHEN} QUIET)
        if (COMPILER_SUPPORTS_${FLAG_NO_HYPHEN})
            list(APPEND ${category}_FLAGS_LIST ${FLAG})
            message(STATUS "Added compiler flag: ${FLAG} to ${category}_FLAGS_LIST")
        else()
            message(STATUS "Flag ${FLAG} is not supported.")
        endif ()
    endforeach()
    set(${flag_list_variable} ${${category}_FLAGS_LIST} PARENT_SCOPE)
endfunction()


# Initialize lists for compiler flags
set(COMMON_FLAGS ${STANDARD_FLAGS})
set(WARNING_FLAGS_LIST)
set(ANALYZER_FLAGS_LIST)
set(DEBUG_FLAGS_LIST)
set(SANITIZER_FLAGS_LIST)

# Add warning flags if supported
add_compile_options_if_supported(WARNING_FLAGS WARNING WARNING_FLAGS_LIST)

# Add analyzer flags if supported
add_compile_options_if_supported(ANALYZER_FLAGS ANALYZER ANALYZER_FLAGS_LIST)

# Check if the DEBUG environment variable is set
add_compile_options_if_supported(DEBUG_FLAGS DEBUG DEBUG_FLAGS_LIST)

# Check if the SANITIZE environment variable is set
add_compile_options_if_supported(SANITIZER_FLAGS SANITIZE SANITIZER_FLAGS_LIST)

# Set compiler flags for the target
target_compile_options(p101_unix PRIVATE
        ${COMMON_FLAGS}
        ${WARNING_FLAGS_LIST}
        ${ANALYZER_FLAGS_LIST}
        ${DEBUG_FLAGS_LIST}
        ${SANITIZER_FLAGS_LIST}
)

# Get compiler flags for the target
get_target_property(COMPILE_OPTIONS p101_unix COMPILE_OPTIONS)
string(REPLACE ";" " " COMPILE_OPTIONS_STR "${COMPILE_OPTIONS}")
message(STATUS "COMPILE_OPTIONS: ${COMPILE_OPTIONS_STR}")

find_program(CLANG_FORMAT NAMES "clang-format" REQUIRED)
find_program(CLANG_TIDY NAMES "clang-tidy" REQUIRED)

# Format source files using clang-format
add_custom_target(format
        COMMAND ${CLANG_FORMAT} --style=file -i ${SOURCES} ${HEADER_LIST} ${HEADER_LIST_ARPA} ${HEADER_LIST_NET} ${HEADER_LIST_SYS}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Running clang-format on source files"
)

# Lint source files using clang-tidy
add_custom_target(lint
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMAND ${CLANG_TIDY} ${SOURCES} -quiet --warnings-as-errors='*' -checks=*,-llvmlibc-restrict-system-libc-headers,-altera-struct-pack-align,-readability-identifier-length,-altera-unroll-loops,-cppcoreguidelines-init-variables,-cert-err33-c,-modernize-macro-to-enum,-bugprone-easily-swappable-parameters,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling,-altera-id-dependent-backward-branch,-concurrency-mt-unsafe,-misc-unused-parameters,-hicpp-signed-bitwise,-google-readability-todo,-cert-msc30-c,-cert-msc50-cpp,-readability-function-cognitive-complexity,-clang-analyzer-security.insecureAPI.strcpy,-cert-env33-c,-android-cloexec-accept,-clang-analyzer-security.insecureAPI.rand,-misc-include-cleaner -- ${CMAKE_C_FLAGS} ${COMMON_FLAGS} -I${CMAKE_SOURCE_DIR}/include -I/usr/local/include
        COMMENT "Running clang-tidy"
)

add_dependencies(p101_unix format)
add_dependencies(p101_unix lint)

# Check if the system uses 64-bit libraries
get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)

# Set the library suffix based on whether it's 64-bit or not
if ("${LIB64}" STREQUAL "TRUE")
    set(LIBSUFFIX 64)
else()
    set(LIBSUFFIX "")
endif()

# Print the LIBSUFFIX variable for debugging
message("LIBSUFFIX: ${LIBSUFFIX}")

# Define the installation directory for libraries
set(INSTALL_LIB_DIR lib${LIBSUFFIX} CACHE PATH "Installation directory for libraries")
mark_as_advanced(INSTALL_LIB_DIR)

set_target_properties(p101_unix PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR})

# Install the library target
install(TARGETS p101_unix
        LIBRARY DESTINATION ${INSTALL_LIB_DIR}
        COMPONENT library
        NAMELINK_COMPONENT development
)

# Install header files
install(FILES ${HEADER_LIST}
        DESTINATION include/p101_unix
)

install(FILES ${HEADER_LIST_ARPA}
        DESTINATION include/p101_unix/arpa
)

install(FILES ${HEADER_LIST_NET}
        DESTINATION include/p101_unix/net
)

install(FILES ${HEADER_LIST_SYS}
        DESTINATION include/p101_unix/sys
)