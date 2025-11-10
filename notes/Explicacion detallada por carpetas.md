
| Carpeta                | Propósito                                             | Contenido sugerido                                                |
| ---------------------- | ----------------------------------------------------- | ----------------------------------------------------------------- |
| **src/**               | Implementación del código fuente                      | `main.cpp`, `process_manager.cpp`, `queue.cpp`, `stack.cpp`, etc. |
| **include/**           | Interfaces, estructuras y definiciones de clases      | `process_manager.hpp`, `queue.hpp`, `stack.hpp`, etc.             |
| **build/**             | Binarios y archivos generados tras compilar           | `finproc`, `*.o`, etc. (añadir al `.gitignore`)                   |
| **docs/report/**       | Informe técnico con capítulos del proyecto            | `report.md`, `report.pdf`, imágenes y diagramas                   |
| **docs/manual/**       | Manual de usuario y guía de instalación               | `user_manual.md`, `user_manual.pdf`                               |
| **docs/diagrams/**     | Diagramas UML, pseudocódigo, flujos, esquemas         | `class_diagram.png`, `flowchart.drawio`                           |
| **slides/**            | Presentación final                                    | `presentation.pptx`, `presentation.pdf`                           |
| **evidence/meetings/** | Actas y registros de reuniones                        | `meeting_01.md`, `meeting_02.md`                                  |
| **evidence/commits/**  | Capturas o reportes de contribuciones                 | `commit_summary.md`, imágenes                                     |
| **evidence/tasks/**    | Plan de trabajo y roles asignados                     | `roles.md`, `schedule.md`                                         |
| **notes/**             | Notas personales o de equipo (para Obsidian)          | Archivos `.md` interconectados con links internos                 |
| **assets/**            | Recursos gráficos usados en informes y presentaciones | Logos, capturas de ejecución, íconos                              |
| **tests/**             | Archivos para probar tus estructuras                  | `test_queue.cpp`, `test_stack.cpp`, etc.                          |
### Estructura de carpetas 
```makefile
FINPROC/
├── src/              # Código fuente (archivos .cpp, .hpp)
├── include/          # Archivos de cabecera (estructuras y clases)
├── build/            # Archivos compilados o ejecutables
├── docs/             # Documentos técnicos (informes, manuales, etc.)
│   ├── report/       # Informe técnico (PDF y archivos fuente)
│   ├── manual/       # Manual de usuario
│   └── diagrams/     # Diagramas UML, flujos, pseudocódigos
├── slides/           # Presentación (PowerPoint o PDF)
├── evidence/         # Evidencias de trabajo en equipo
│   ├── meetings/     # Actas de reuniones (texto o imágenes)
│   ├── commits/      # Capturas o resúmenes de commits
│   └── tasks/        # Plan de trabajo y roles
├── notes/            # Notas personales o de equipo (para usar con Obsidian)
├── assets/           # Imágenes, íconos, capturas de pantalla
├── tests/            # Pruebas unitarias o ejemplos de ejecución
├── Dockerfile        # Entorno de desarrollo
├── Makefile          # Compilación del código
├── README.md         # Descripción general del proyecto
└── .gitignore

```

## Principales Plgins

| Nombre del plugin                                                                | Qué hace                                                                                                                                | Por qué lo necesitas                                                                                                         |
| -------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| [**Kanban**](https://github.com/mgmeyers/obsidian-kanban)                        | Permite crear tableros Kanban dentro de Obsidian (columnas “To Do”, “In Progress”, “Done”)                                              | Ideal para aplicar SCRUM, gestionar tareas del equipo, ver visualmente qué está en cada sprint.                              |
| [**Tasks**](https://github.com/obsidian-tasks-group/obsidian-tasks)              | Plugin de gestión de tareas en markdown, permite filtrar, mostrar tareas según estados, fechas, etc. ([Obsidian Forum][1])              | Perfecto para llevar el backlog, tareas, asignaciones individuales, estados de cada ítem de trabajo.                         |
| [**Dataview**](https://github.com/blacksmithgu/obsidian-dataview)                | Permite hacer consultas sobre tus notas (metadata, tags, estados) y generar vistas dinámicas                                            | Muy útil para, por ejemplo, listar todas las tareas de un sprint, agrupar por estado, generar reportes automáticos.          |
| [**Charts**](https://github.com/phibr0/obsidian-charts)                          | Permite generar gráficos interactivos (barras, líneas, etc.) dentro de Obsidian mediante plugins como Chart.js. ([Charts Plugin][2])    | Para generar métricas visuales del proyecto: número de tareas completadas, velocidad del equipo, evolución del backlog, etc. |
| [**Calendar**](https://github.com/liamcain/obsidian-calendar-plugin)             | Añade vista de calendario para tus notas / tareas / plazos. ([Medium][4])                                                               | Útil para gestionar tus sprints, fechas de entrega, revisiones, informes, etc.                                               |
| [**Agile Task Notes**](https://github.com/BoxThatBeat/obsidian-agile-task-notes) | Especializado para metodología ágil: gestión de tareas estilo SCRUM, Kanban, integración de plantillas de tareas. ([Obsidian Stats][5]) | Directamente alineado con tu necesidad de SCRUM: sprints, roles de equipo, dashboards de tareas.                             |

#### Estructura propuesta
```text
FINPROC/
├── src/                  # Código fuente (.cpp)
│   ├── main.cpp
│   ├── process_manager.cpp
│   ├── queue.cpp
│   └── stack.cpp
│
├── include/              # Archivos de cabecera (.hpp)
│   ├── process_manager.hpp
│   ├── queue.hpp
│   └── stack.hpp
│
├── tests/                # Pruebas unitarias y ejemplos
│   ├── test_queue.cpp
│   └── test_stack.cpp
│
├── build/                # Binarios y archivos compilados (añadir a .gitignore)
│   └── finproc
│
├── docs/                 # Documentación técnica formal
│   ├── report/           # Informe técnico (capítulos, PDFs)
│   │   ├── report.md
│   │   ├── report.pdf
│   │   └── figures/
│   ├── manual/           # Manual de usuario
│   │   ├── user_manual.md
│   │   └── user_manual.pdf
│   └── diagrams/         # Diagramas UML, flujos, pseudocódigos
│       ├── class_diagram.excalidraw
│       ├── flowchart.png
│       └── pseudocode.md
│
├── slides/               # Presentación final
│   ├── presentation.pptx
│   └── presentation.pdf
│
├── project/              # Gestión del proyecto (SCRUM, Obsidian)
│   ├── backlog.md
│   ├── sprint_plan.md
│   ├── kanban.md
│   ├── retrospective.md
│   └── metrics.md
│
├── evidence/             # Evidencias de trabajo en equipo
│   ├── meetings/         # Actas y capturas de reuniones
│   │   ├── meeting_01.md
│   │   └── meeting_02.md
│   ├── commits/          # Reportes o imágenes de commits
│   │   └── commit_summary.md
│   └── tasks/            # Roles, plan de trabajo, asignaciones
│       ├── roles.md
│       └── schedule.md
│
├── notes/                # Notas personales / equipo (para Obsidian)
│   ├── ideas.md
│   ├── definitions.md
│   └── bibliography.md
│
├── assets/               # Recursos gráficos generales
│   ├── logos/
│   ├── screenshots/
│   └── icons/
│
├── Makefile              # Compilación
├── Dockerfile            # Entorno de desarrollo C++
├── README.md             # Descripción general
├── .gitignore
└── LICENSE

```

#### Razones del redise;o
|Mejora|Explicación|
|---|---|
|`project/`|Separa la parte **SCRUM y de gestión ágil** del resto de documentación. Ideal si usas **Obsidian Kanban** o **Agile Task Notes**.|
|`docs/`|Queda solo para el **informe técnico y documentación formal**, más limpio para el profesor y entregas PDF.|
|`evidence/`|Conserva tus **actas, roles y reportes de trabajo**, todo rastreable para evidenciar trabajo en equipo.|
|`assets/`|Evita duplicar imágenes entre el informe, la presentación y las evidencias. Centraliza todo.|
|`notes/`|Ideal para tu **vault de Obsidian** (puedes sincronizarlo directamente con tu carpeta local de Obsidian).|
