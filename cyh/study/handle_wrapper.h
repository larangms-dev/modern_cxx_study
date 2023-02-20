#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class HandleWrapper
{
public:
	HandleWrapper() noexcept;
	HandleWrapper(const HandleWrapper& other) noexcept;
	HandleWrapper(HandleWrapper&& other) noexcept;
	HandleWrapper(const HANDLE& handle) noexcept;
	HandleWrapper(HANDLE&& handle) noexcept;
	~HandleWrapper();
public:
	HandleWrapper& operator=(const HandleWrapper& other) noexcept;
	HandleWrapper& operator=(HandleWrapper&& other) noexcept;
	HandleWrapper& operator=(const HANDLE& handle) noexcept;
	HandleWrapper& operator=(HANDLE&& handle) noexcept;
	operator HANDLE() const;
public:
	//const HANDLE& Get() const noexcept;
	bool IsValid() const noexcept;
private:
	HANDLE handle;
};