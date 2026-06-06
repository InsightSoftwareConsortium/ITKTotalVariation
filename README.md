# Migrated to ITK main

The `TotalVariation` module has been ingested into the Insight Toolkit (ITK) main repository and is no longer maintained here.

- **In-tree location:** [`Modules/Filtering/TotalVariation`](https://github.com/InsightSoftwareConsortium/ITK/tree/main/Modules/Filtering/TotalVariation)
- **Ingest PR:** [InsightSoftwareConsortium/ITK#6381](https://github.com/InsightSoftwareConsortium/ITK/pull/6381)
- **Merge commit:** [`3609b55578`](https://github.com/InsightSoftwareConsortium/ITK/commit/3609b5557840454bb83527fb2e88684474841b2a)

The bundled `proxTV` dependency is now provided in ITK main as the `Modules/ThirdParty/proxTV` third-party module.

Future development, bug fixes, and pull requests should target ITK main. This repository's history is preserved for `git blame` and archival reference. The original module description is preserved in [`info.rst`](info.rst).

**Maintainer action:** this repository is **Archived** (read-only). See the [ITK ingestion strategy](https://github.com/InsightSoftwareConsortium/ITK/blob/main/Utilities/Maintenance/RemoteModuleIngest/INGESTION_STRATEGY.md) for context.
