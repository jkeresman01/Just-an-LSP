# Just-an-LSP
Language Server is to provide the language-specific smarts inside a server that can communicate with development tooling over a protocol that enables inter-process communication.

#Neovim as client
```Lua
local client = vim.lsp.start({
    name = 'just-an-lsp',
    cmd = {'/path/to/just-an-lsp/binary'}
})

vim.api.nvim_create_autocmd("FileType", {
    pattern = "text",
    callback = function()
        vim.lsp.buf_attach_client(0, client)
    end
})
```
