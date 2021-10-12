#include "lazy_tensor_core/csrc/ops/cholesky.h"


namespace torch_lazy_tensors {
namespace ir {
namespace ops {

Cholesky::Cholesky(const Value& input, bool lower)
    : Node(ir::OpKind(at::aten::cholesky), {input}, input.shape(),
           /*num_outputs=*/1, torch::lazy::MHash(lower)),
      lower_(lower) {}

NodePtr Cholesky::Clone(OpList operands) const {
  return MakeNode<Cholesky>(operands.at(0), lower_);
}

std::string Cholesky::ToString() const {
  std::stringstream ss;
  ss << Node::ToString() << ", lower=" << lower_;
  return ss.str();
}

}  // namespace ops
}  // namespace ir
}  // namespace torch_lazy_tensors