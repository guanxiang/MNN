//
//  RangeBufExecution.hpp
//  MNN
//
//  Created by MNN on 2023/12/1.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef RangeExecution_hpp
#define RangeExecution_hpp

#include "core/Execution.hpp"

#include <vector>
#include "MNN_generated.h"
#include "backend/opencl/core/OpenCLBackend.hpp"
#include "backend/opencl/core/OpenCLRunningUtils.hpp"
#include "backend/opencl/execution/image/CommonExtension.hpp"

namespace MNN {
namespace OpenCL {

class RangeExecution : public Execution, public CommonExtension {
public:
    RangeExecution(const std::string &compute, Backend *backend);
    virtual ~RangeExecution() = default;

    virtual ErrorCode onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;
    virtual ErrorCode onExecute(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) override;

private:
    cl::Kernel mKernel;
    uint32_t mMaxWorkGroupSize;
    std::vector<uint32_t> mGlobalWorkSize = {1, 1, 1};
    std::vector<uint32_t> mLocalSize      = {1, 1, 1};
    std::set<std::string> mBuildOptions;
};

} // namespace OpenCL
} // namespace MNN
#endif /* RangeExecution_hpp */
