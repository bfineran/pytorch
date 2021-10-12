#include "lazy_tensor_core/csrc/ops/uniform.h"

#include "lazy_tensors/computation_client/util.h"
#include "lazy_tensors/shape_util.h"

namespace torch_lazy_tensors {
namespace ir {
namespace ops {

Uniform::Uniform(const Value& from, const Value& to, const Value& seed,
                 const lazy_tensors::Shape& rng_shape)
    : Node(ir::OpKind(at::aten::uniform), {from, to, seed}, rng_shape,
           /*num_outputs=*/1, torch::lazy::Hash(rng_shape)) {}

NodePtr Uniform::Clone(OpList operands) const {
  return MakeNode<Uniform>(operands.at(0), operands.at(1), operands.at(2),
                           shape());
}

}  // namespace ops
}  // namespace ir
}  // namespace torch_lazy_tensors