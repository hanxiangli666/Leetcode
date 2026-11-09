# 飞书力扣刷题群

这是 James 的私人刷题入口。飞书群主发文字、代码、题目链接或截图，程序把消息交给同一个 Codex 对话，再由群里的机器人回复。中文教学规则见 [coach.md](coach.md)。

程序复用本机已经登录的 `lark-cli` 和 `codex`，不复制凭据。新群使用 CLI 自己的机器人，与「开发团队」里的元禧机器人使用不同应用、进程和状态目录。

## 运行方式

- 程序：`integrations/feishu-coach/bridge.py`，Python 3.9 以上，无新增第三方依赖。
- 本机设置、队列和会话编号：`~/.local/share/leetcode-feishu/`，不在 Git 仓库中。
- 常驻入口：`~/Library/LaunchAgents/local.leetcode.feishu-coach.plist`，登录后自动运行、退出后自动重启。
- 收消息使用 `lark-cli event consume im.message.receive_v1`；同时核对本群的新消息，普通发言无需 @。空闲时每 20 秒检查，连续聊天期间每 5 秒检查，休眠或网络中断后的消息也可以补取。
- 开始处理消息前先发「收到」提示，再生成完整回答，避免长时间无反馈；确认提示失败时仍继续回答。相同消息重复送达不会重复提示或重复处理。
- 两条接收途径按 `message_id` 去重，同一分钟内按收到的先后顺序处理；bot 消息、其他群消息和非群主消息不交给模型。
- 完成后的本地任务只保留去重记录，清空消息正文与回复正文；连续对话由 Codex 会话维持。没有额外写入 Obsidian 或聊天归档。
- 回复按稳定编号发送，网络重试不重新运行模型任务。若处理过程被中断，不自动重跑可能已经执行的提交操作。
- 图片和代码附件只下载到本机私有状态目录。模型使用工作区写入范围，提交沿用项目的明确授权规则。
- Git 保存（2026-11-09）：Codex 沙箱不能写 `.git`，模型在回复末尾输出 `git-save` 块（`paths` 限 `us/` 下、`message`），程序在沙箱外 `git add/commit/push`，把结果接在回复后面；被忽略、没改动、推送失败都原样报出。
- 每日推送（2026-11-09）：`config.json` 的 `daily_push`（默认北京时间 9:00，`latest_hour` 之前补发，一天一次）排一条合成消息，模型按 `coach.md`「每日推送」主动发内容，发过的主题记在 `pushed-topics.md`。手动补一条：`python3 integrations/feishu-coach/bridge.py daily-now`。
- 模型：`config.json` 的 `codex_model`（默认 `gpt-6.1-sol`）和 `codex_effort`（默认 `medium`，兼顾速度和讲解质量）；只用 Codex 额度。`coach.md` 改了之后，已有对话下一轮会自动收到新规则。
- 指针图按真实下标生成纯 ASCII 等宽 Markdown：字符、箭头和 left/right 标签在同一列；较长例子改为明确的下标映射，避免手机换行。真实 C++ 代码的内容与缩进不经图示转换。显示规则每轮重新读取，已有对话也会立即采用修正。

运行状态：

```sh
python3 integrations/feishu-coach/bridge.py status
```

验证边界与格式：

```sh
PYTHONDONTWRITEBYTECODE=1 python3 integrations/feishu-coach/test_bridge.py
```

查询一个美国站题目的真实状态（不会输出凭据）：

```sh
python3 integrations/feishu-coach/leetcode_status.py valid-palindrome
```

这项服务依赖 Mac 开机、登录、联网，以及飞书和 Codex 登录有效；电脑休眠或额度用完时不会即时回复。它不是已部署到云端的全天候服务。

实现接口依据：[Codex 官方非交互模式](https://learn.chatgpt.com/docs/non-interactive-mode)，以及本机 `lark-cli skills read lark-event`、`lark-cli skills read lark-im` 的当前说明。
