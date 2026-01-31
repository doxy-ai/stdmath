#include <type_traits>
#include <utility>

template <typename, typename F, typename... Args>
struct return_or_void_impl {
    using type = void;
};

template <typename F, typename... Args>
struct return_or_void_impl<std::void_t<std::invoke_result_t<F, Args...>>, F, Args...> {
    using type = std::invoke_result_t<F, Args...>;
};

template <typename F, typename... Args>
using return_or_void_t = typename return_or_void_impl<void, F, Args...>::type;