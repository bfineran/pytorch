#include "lazy_tensor_core/csrc/ops/tril.h"


namespace torch_lazy_tensors {
namespace ir {
namespace ops {

Tril::Tril(const Value& input, lazy_tensors::int64 diagonal)
    : TsNode(ir::OpKind(at::aten::tril), {input}, GetShapeFromTsValue(input),
           /*num_outputs=*/1, torch::lazy::MHash(diagonal)),
      diagonal_(diagonal) {}

NodePtr Tril::Clone(OpList operands) const {
  return MakeNode<Tril>(operands.at(0), diagonal_);
}

std::string Tril::ToString() const {
  std::stringstream ss;
  ss << TsNode::ToString() << ", diagonal=" << diagonal_;
  return ss.str();
}

}  // namespace ops
}  // namespace ir
}  // namespace torch_lazy_tensors