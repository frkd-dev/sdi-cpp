#pragma once

/**
 * \brief Creator is an extremely simple, but helpful dependency injection mechanism implementing a Dependency Inversion principle from SOLID based on couple of templates and two just methods.
 */

#include <functional>
#include <memory>

#include "CreatorVariants.hpp"

template <class ReturnType, Variant, class... Args>
using Creator = std::function<ReturnType(Args...)>;

template <class ReturnType, Variant Var, class... Args>
Creator<ReturnType, Var, Args...> getCreator();

template <class ReturnType, Variant Var, class... Args, class ManagedReturnType = std::unique_ptr<ReturnType>>
ManagedReturnType
createUnique(Args... args)
{
    return getCreator<ManagedReturnType, Var, Args...>()(args...);
}

template <class ReturnType, Variant Var, class... Args, class ManagedReturnType = std::shared_ptr<ReturnType>>
ManagedReturnType
createShared(Args... args)
{
    return getCreator<ManagedReturnType, Var, Args...>()(args...);
}
