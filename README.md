# !!!!!!!!!!!!!! &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; THIS ISN'T BAKED YET &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;   !!!!!!!!!!!!!!
# Just-an-LSP
Just-an-LSP is an attempt to build a toy Language Server for the C++ programming language.

# LSP overivew
The idea behind the Language Server Protocol (LSP) is to standardize the protocol for how tools and servers communicate, so a single Language Server can be re-used in multiple development tools, and tools can support languages with minimal effort.

## How it works
A language server runs as a separate process and development tools communicate with the server using the language protocol over JSON-RPC. 

Below is an example for how a tool and a language server communicate during a routine editing session:
![image](https://github.com/jkeresman01/Just-an-LSP/assets/165517653/6c92eaf4-3656-48b2-8716-597aab1bea4c)

Detailed LSP specifications: https://microsoft.github.io/language-server-protocol/specifications/lsp/3.17/specification/ 

## Neovim as client
Nvim supports the Language Server Protocol (LSP), which means it acts as a client to LSP servers and includes a Lua framework `vim.lsp`.

To configure the LSP client, you can use this example:

```Lua
local client = vim.lsp.start({
    name = 'just-an-lsp',
    cmd = {'/path/to/just-an-lsp/binary'}
})

if not client then
    vim.notify "No can do for just-an-lsp!"
end

vim.api.nvim_create_autocmd("FileType", {
    pattern = "cpp",
    callback = function()
        vim.lsp.buf_attach_client(0, client)
    end
})
```
Afterwards you can check that the server is attached to the buffer:

```Lua
:lua =vim.lsp.get_clients()
```
