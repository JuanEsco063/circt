//===- RTLTypes.h - types for the RTL dialect -------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Types for the RTL dialect are mostly in tablegen. This file should contain
// C++ types used in MLIR type parameters.
//
//===----------------------------------------------------------------------===//

#ifndef CIRCT_DIALECT_RTL_TYPES_H
#define CIRCT_DIALECT_RTL_TYPES_H

#include "mlir/IR/Types.h"

#define GET_TYPEDEF_CLASSES
#include "circt/Dialect/RTL/RTLTypes.h.inc"

namespace circt {
namespace rtl {

/// Return true if the specified type is a value RTL Integer type.  This checks
/// that it is a signless standard dialect type and that it isn't zero bits.
bool isRTLIntegerType(mlir::Type type);

/// Return true if the specified type can be used as an RTL value type, that is
/// the set of types that can be composed together to represent synthesized,
/// hardware but not marker types like InOutType or unknown types from other
/// dialects.
bool isRTLValueType(mlir::Type type);

/// Return true if the specified type contains known marker types like
/// InOutType.  Unlike isRTLValueType, this is not conservative, it only returns
/// false on known InOut types, rather than any unknown types.
bool hasRTLInOutType(mlir::Type type);

/// Return the element type of an InOutType or null if the operand isn't an
/// InOut type.
mlir::Type getInOutElementType(mlir::Type type);

/// Return the element type of an ArrayType or UnpackedArrayType, or null if the
/// operand isn't an array.
mlir::Type getAnyRTLArrayElementType(mlir::Type type);

} // namespace rtl
} // namespace circt

#endif // CIRCT_DIALECT_RTL_TYPES_H
