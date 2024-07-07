# Just-an-LSP
Language Server is to provide the language-specific smarts inside a server that can communicate with development tooling over a protocol that enables inter-process communication.

## Neovim as client
Nvim supports the Language Server Protocol (LSP), which means it acts as a client to LSP servers and includes a Lua framework `vim.lsp` for building enhanced LSP tools.

Configure the LSP client per language server:

```Lua
local client = vim.lsp.start({
    name = 'just-an-lsp',
    cmd = {'/path/to/just-an-lsp/binary'}
})

if not client then
    vim.notify "No can do for just-an-lsp!"
end

vim.api.nvim_create_autocmd("FileType", {
    pattern = "text",
    callback = function()
        vim.lsp.buf_attach_client(0, client)
    end
})
```
Check that the server is attached to the buffer:

```Lua
:lua =vim.lsp.get_clients()
```
