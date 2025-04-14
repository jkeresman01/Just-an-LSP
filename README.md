
<div align="center">

  <h1>Just-an-LSP</h1>
  <h3> !!!!!!!   Not baked yet   !!!!!!! </h3>
  <h6> ---> Toy langauge server for C++, just for funzies <--- </h6>

![C++](https://img.shields.io/badge/C++-blue?style=for-the-badge&logo=c%2B%2B)
![Work In Progress](https://img.shields.io/badge/Work%20In%20Progress-orange?style=for-the-badge)

</div>

# Just-an-LSP #
Just me and myself trying to build language server for C++ programming language

# LSP overivew #
The idea behind the Language Server Protocol (LSP) is to standardize the protocol for how tools and servers communicate, so a single Language Server can be re-used in multiple development tools, and tools can support languages with minimal effort.

## How it works ##
A language server runs as a separate process and development tools communicate with the server using the language protocol over JSON-RPC. 

Below is an example for how a tool and a language server communicate during a routine editing session:
![image](https://github.com/jkeresman01/Just-an-LSP/assets/165517653/6c92eaf4-3656-48b2-8716-597aab1bea4c)

Detailed LSP specifications: https://microsoft.github.io/language-server-protocol/specifications/lsp/3.17/specification/ 

## Neovim as client ## 
Nvim supports the Language Server Protocol (LSP), which means it acts as a client to LSP servers and includes a Lua framework `vim.lsp`.

To configure the LSP client, you can use this example:

```Lua
vim.api.nvim_create_autocmd("FileType", {
    pattern = "cpp",

    callback = function()

        local client = vim.lsp.start({
            name = "JustAnLSP",
            cmd = {"/path/to/JustAnLSPServer/binary"}
        })

        if not client then
            vim.notify "No can do for JustAnLSPServer!"
        else
            vim.lsp.buf_attach_client(0, client)
        end
    end

})
